#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct _node
{
    int data;
    struct _node* prev;
    struct _node* next;    
} node;
 
typedef struct _deque
{
    node* front;
    node* back;
    int size;
} deque;
 
void deque_init(deque* pd)
{
    pd->front=NULL;
    pd->back=NULL;
    pd->size=0;
};
 
int deque_empty(deque* pd)
{
    if(pd->size==0) return 1;
    else return 0;
};
 
void deque_push_front(deque* pd, int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(deque_empty(pd))
    {
    	pd->front=newnode;
    	pd->back=newnode;
	}
	else
	{
		newnode->next=pd->front;
		pd->front->prev=newnode;
		pd->front=newnode;
	}
    (pd->size)++;
};

void deque_push_back(deque* pd, int data)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(deque_empty(pd))
    {
    	pd->front=newnode;
    	pd->back=newnode;
	}
	else
	{
		newnode->prev=pd->back;
		pd->back->next=newnode;
		pd->back=newnode;
	}
    (pd->size)++;
};

int deque_pop_front(deque* pd)
{
    if(deque_empty(pd)) return -1;
     
    node* rnode=pd->front;
    int rdata=rnode->data;
     
   	pd->front=pd->front->next;
   	if(pd->front!=NULL) pd->front->prev=NULL;
   	else pd->back=NULL;
    free(rnode);
    (pd->size)--;
    return rdata;
};

int deque_pop_back(deque* pd)
{
    if(deque_empty(pd)) return -1;
     
    node* rnode=pd->back;
    int rdata=rnode->data;
     
   	pd->back=pd->back->prev;
   	if(pd->back!=NULL) pd->back->next=NULL;
   	else pd->front=NULL;
    free(rnode);
    (pd->size)--;
    return rdata;
};

int deque_front(deque* pd)
{
    if(deque_empty(pd)) return -1;
    else return pd->front->data;
};

int deque_back(deque* pd)
{
    if(deque_empty(pd)) return -1;
    else return pd->back->data;
};

int deque_size(deque* pd)
{
    return pd->size;
};

int main()
{
    deque d;
    deque_init(&d);
 
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        char a[11]={0};
        scanf("%s",a);
        if(!strncmp(a,"push_front",10))
        {
            int x;
            scanf("%d",&x);
            deque_push_front(&d,x);
        }
        else if(!strncmp(a,"push_back",9))
        {
            int x;
            scanf("%d",&x);
            deque_push_back(&d,x);
        }
        else if(!strncmp(a,"pop_front",9)) printf("%d\n",deque_pop_front(&d));
        else if(!strncmp(a,"pop_back",8)) printf("%d\n",deque_pop_back(&d));
        else if(!strncmp(a,"size",4)) printf("%d\n",deque_size(&d));
        else if(!strncmp(a,"empty",5)) printf("%d\n",deque_empty(&d));
        else if(!strncmp(a,"front",5)) printf("%d\n",deque_front(&d));
        else if(!strncmp(a,"back",4)) printf("%d\n",deque_back(&d));
    }
    return 0;
}