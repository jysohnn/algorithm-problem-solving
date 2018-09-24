#include <stdio.h>
#include <algorithm>

using namespace std;

int m,n,t;
int map[100][100];
int v[100][100] = {0};
int sol[10000];
int top = 0;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

bool boundarycheck(int x,int y)
{
	if(x >= 0 && x < m && y >=0 && y < n) return true;
	else return false;
}

int dfs(int x,int y)
{
	int ret = 1;
	v[x][y] = 1;
	for(int i=0;i<4;i++)
		if(boundarycheck(x+dx[i],y+dy[i]) && !v[x+dx[i]][y+dy[i]] && map[x+dx[i]][y+dy[i]]) ret += dfs(x+dx[i],y+dy[i]);
	return ret;
}

int main()
{
	scanf("%d %d %d",&m,&n,&t);
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++) map[i][j] = 1;
	while(t--)
	{
		int sx,ex,sy,ey;
		scanf("%d %d %d %d",&sy,&sx,&ey,&ex);
		for(int i = sx; i < ex; i++) 
			for(int j = sy; j < ey; j++) map[i][j] = 0, v[i][j] = 1;
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(!v[i][j]) sol[top++] = dfs(i,j);
	sort(sol,sol+top);
	printf("%d\n",top);
	for(int i=0;i<top;i++) printf("%d ",sol[i]);
	
	return 0;
}