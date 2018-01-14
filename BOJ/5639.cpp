#include <cstdio>
#define INF 999999

struct node
{
	int data;
	node* left;
	node* right;
	node():left(NULL),right(NULL){}
	void setleft(node* nd){left=nd;}
	void setright(node* nd){right=nd;}
};

int a[10001];
int idx = 0, n = 0;

node* maketree(int min, int max)
{
	if(idx >= n) return NULL;
	if(a[idx] < min || a[idx] > max) return NULL;
	else
	{
		node* root = new node;
		root->data = a[idx++];
		if(a[idx] < root->data) root->setleft(maketree(min,root->data));
		if(a[idx] > root->data) root->setright(maketree(root->data,max));
		return root;
	}
}

void postorder(node* root)
{
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\n",root->data);
}

int main()
{
	node* root;
	for(int i=0;1;i++)
	{
		int x;
		if(scanf("%d",&x) == EOF) break;
		a[i]=x;
		n=i+1;
	}
	root = maketree(0,INF);
	postorder(root);
	return 0;
}