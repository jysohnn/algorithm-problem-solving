#include <cstdio>

int n,x,y,m;
bool adj[100][100] = {0};
bool v[100] = {0};
int l[100];

int q[102];
int front=0,rear=0;

int bfs(int x,int y)
{
	l[x] = 0;
    v[x] = 1;
	q[rear++] = x;

	while(front != rear)
	{
		int pos = q[front++];
		if(pos == y) return l[pos];
		for(int i=0;i<n;i++)
			if(adj[pos][i] && !v[i])
			{
				v[i] = 1;
				q[rear++] = i;
				l[i] = l[pos] + 1;
			}
	}
    return -1;
}

int main()
{
	scanf("%d %d %d %d",&n,&x,&y,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a-1][b-1] = true;
		adj[b-1][a-1] = true;
	}
	printf("%d",bfs(x-1,y-1));
	return 0;
}