#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
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

void stack_push(stack* ps, int data)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
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

int stack_size(stack* ps)
{
	return ps->size;
};

int main()
{
	stack s,t;
	stack_init(&s);
	stack_init(&t);
	int n,i;
	int num=1;
	
	scanf("%d",&n);
	int* x=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",x+i);
	
	for(i=0;i<n;i++)
	{
		if(stack_top(&t)<x[i])
		{
			while(stack_top(&t)!=x[i])
			{
				stack_push(&t,num);
				num++;
			}
			stack_pop(&t);
		}
		else if(stack_top(&t)==x[i])
		{
			stack_pop(&t);
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	
	num=1;
	for(i=0;i<n;i++)
	{
		if(stack_top(&s)<x[i])
		{
			while(stack_top(&s)!=x[i])
			{
				stack_push(&s,num);
				printf("+\n");
				num++;
			}
			stack_pop(&s);
			printf("-\n");
		}
		else if(stack_top(&s)==x[i])
		{
			stack_pop(&s);
			printf("-\n");
		}
	}
	return 0;
}