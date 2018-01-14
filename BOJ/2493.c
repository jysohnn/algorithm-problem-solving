#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	int idx;
	struct _node* next;
} node;

typedef struct _stack
{
	node* top;
	int size;
} stack;

void stack_init(stack* ps)
{
	ps->top=NULL;
	ps->size=0;
};

int stack_empty(stack* ps)
{
	if(ps->size==0) return 1;
	else return 0;
};

void stack_push(stack* ps, int data, int idx)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->idx=idx;
	newnode->next=ps->top;
	ps->top=newnode;
	(ps->size)++;
};

int stack_pop(stack* ps)
{
	if(stack_empty(ps)) return -1;
	
	node* rnode=ps->top;
	int rdata=rnode->data;
	
	ps->top=ps->top->next;
	free(rnode);
	(ps->size)--;
	return rdata;
};

int stack_top(stack* ps)
{
	if(stack_empty(ps)) return -1;
	else return ps->top->data;
};

int stack_topidx(stack* ps)
{
	if(stack_empty(ps)) return 0;
	else return ps->top->idx; 	
};

int stack_size(stack* ps)
{
	return ps->size;
};

int main()
{
	stack s;
	stack_init(&s);
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while(s.size!=0&&x>=stack_top(&s)) stack_pop(&s);
		if(i==1) printf("%d",stack_topidx(&s));
		else printf(" %d",stack_topidx(&s));
		stack_push(&s,x,i);
	}
	return 0;
}