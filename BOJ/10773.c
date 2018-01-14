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
    int n,sum=0;
    stack s;
    stack_init(&s);
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if(x==0) stack_pop(&s);
        else stack_push(&s,x);
    }
    while(!stack_empty(&s))
    {
        sum+=stack_pop(&s);
    }
    printf("%d",sum);
    return 0;
}