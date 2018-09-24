#include <stdio.h>
#include <stdlib.h>
#define LEFT 0
#define RIGHT 1

typedef struct _node
{
	char data;
	struct _node* left;
	struct _node* right;
} node;

void makesubtree(node* main, node* sub, int dir)
{
	if(dir==LEFT) main->left = sub;
	else main->right = sub;
};

void intraversal(node* main)
{
	if(main!=NULL)
	{
		intraversal(main->left);
		printf("%c",main->data);
		intraversal(main->right);
	}
};
void pretraversal(node* main)
{
	if(main!=NULL)
	{
		printf("%c",main->data);
		pretraversal(main->left);	
		pretraversal(main->right);
	}
};
void postraversal(node* main)
{
	if(main!=NULL)
	{
		postraversal(main->left);	
		postraversal(main->right);
		printf("%c",main->data);
	}
};

int main()
{
	int n,i;
	scanf("%d",&n);
	node* a=(node*)malloc(sizeof(node)*n);
	for(i=0;i<n;i++) {a[i].data=i+65;a[i].left=NULL;a[i].right=NULL;}
	for(i=0;i<n;i++)
	{
		char main,left,right;
		getchar();
		scanf("%c %c %c",&main,&left,&right);
		if(left!='.') makesubtree(&(a[main-65]),&(a[left-65]),LEFT);
		if(right!='.') makesubtree(&(a[main-65]),&(a[right-65]),RIGHT);
	}
	pretraversal(&(a[0]));
	printf("\n");
	intraversal(&(a[0]));
	printf("\n");
	postraversal(&(a[0]));
	printf("\n");
	return 0;
}