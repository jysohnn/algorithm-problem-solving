#include <stdio.h>
typedef struct
{   int v;
	int e;
	int adj[100][100];
	int visit[100];
} graph;
void graph_init(graph* g,int v,int e)
{
	int i,j;
	g->v=v;
	g->e=e;
	for(i=0;i<v;i++)
    {
        g->visit[i]=0;
        for(j=0;j<v;j++) g->adj[i][j]=0;
    }
};
int dfs(graph* g, int from, int target)
{	
	int i;
	g->visit[from]=1;
	for(i=0;i<(g->v);i++)
		if(g->adj[from][i]==1) 
		{
			if(i==target) return 1;
			if(g->visit[i]==0 && dfs(g,i,target)==1) return 1;
		}
	return 0;
};
int main()
{
	int n,i,j,k;
	graph g;
	scanf("%d",&n);
	graph_init(&g,n,n*n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
		{
			int x;
			scanf("%d",&x);
			if(x==1) g.adj[i][j]=1;
		}
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++) 
		{
			if(j!=0) putchar(' ');
			printf("%d",dfs(&g,i,j));
			for(k=0;k<n;k++) g.visit[k]=0;
		}
		putchar('\n');
	}
	return 0;
}