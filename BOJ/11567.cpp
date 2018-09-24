#include <iostream>

using namespace std;

int n,m,x,y,xx,yy;
bool a[501][501] = {0};
bool sol = 0;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

bool bc(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y)
{
	a[x][y] = 0;
	for(int i=0;i<4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx == xx && ny == yy && !a[nx][ny]) {sol = 1; return;}
		if(bc(nx,ny) && a[nx][ny]) dfs(nx,ny);
		if(sol) return;
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		getchar();
		for(int j=0;j<m;j++)
		{
			char x = getchar();
			if(x == '.') a[i][j] = 1;
		}
	}
	cin>>x>>y>>xx>>yy;
	x--;y--;xx--;yy--;
	dfs(x,y);
	if(sol) cout<<"YES";
	else cout<<"NO";
	return 0;
}