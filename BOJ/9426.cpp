#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
	int data;
	int size;
	int pr;
	node* left;
	node* right;
	node(int _data) :data(_data),size(1),pr(rand()),left(NULL),right(NULL){}
	void cal()
	{
		size = 1;
		if(left!=NULL)size += left->size;
		if(right!=NULL)size += right->size;
	}
	node* setleft(node* nd)
	{
		left = nd;
		cal();	
	}
	node* setright(node* nd)
	{
		right = nd;
		cal();	
	}
};

typedef pair<node*,node*> pairnode;

pairnode split(node* root,int data)
{
	if(root == NULL) return pairnode(NULL,NULL);
	if(root->data > data)
	{
		pairnode lst = split(root->left,data);
		root->setleft(lst.second);
		return pairnode(lst.first,root);
	}
	else
	{
		pairnode rst = split(root->right,data);
		root->setright(rst.first);
		return pairnode(root,rst.second);
	}
}
node* insert(node* root,node* nd)
{
	if(root == NULL) return nd;
	if(root->pr > nd->pr)
	{
		if(root->data > nd->data) root->setleft(insert(root->left,nd));
		else root->setright(insert(root->right,nd));
		return root;
	}
	else
	{
		pairnode twosub = split(root,nd->data);
		nd->setleft(twosub.first);
		nd->setright(twosub.second); 
		return nd;
	}
}
node* merge(node* a,node* b) //max(a) < min(b)
{
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->pr > b->pr)
	{
		a->setright(merge(a->right,b));
		return a;
	}
	else
	{
		b->setleft(merge(a,b->left));
		return b;
	}
}
node* erase(node* root,int data)
{
	if(root == NULL) return root;
	if(root->data == data)
	{
		node* del = root;
		root = merge(root->left,root->right);
		delete del;
	}
	else if(root->data > data) root->setleft(erase(root->left,data));
	else root->setright(erase(root->right,data));
	
	return root;
}
node* kth(node* root,int k)
{
	int leftsize = 0;
	if(root->left != NULL) leftsize = root->left->size;
	if(leftsize + 1 == k) return root;
	else if(leftsize >= k) return kth(root->left,k);
	else return kth(root->right, k - leftsize - 1);
}

int main()
{
	node* root = NULL;
	long long sum = 0;
	int n,k;
	scanf("%d %d",&n,&k);
	int* a = new int[n];
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<k;i++) root = insert(root,new node(a[i]));
	node* tmp = kth(root,(k+1)/2);
	sum += tmp->data;
	for(int i=k;i<n;i++)
	{
		root = erase(root,a[i-k]);
		root = insert(root,new node(a[i]));
		node* tmp = kth(root,(k+1)/2);
		sum += tmp->data;
	}
	printf("%lld",sum);
	return 0;
}