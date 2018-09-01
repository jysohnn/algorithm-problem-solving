#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
int n,m,x,y,dir;
int a[51][51] = {0};
int c[51][51] = {0};
int sol = 0;

bool bc(int x, int y) {return x >= 0 && x < n && y >= 0 && y < m;}

void solve(int x, int y, int dir)
{
	bool check = true;
	if(!c[x][y]) c[x][y] = 1, sol++;
	for(int i=0;i<4;i++)
	{
		dir = (dir+3) % 4;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if(bc(nx,ny) && !a[nx][ny] && !c[nx][ny])
		{
			solve(nx,ny,dir);
			check = false;
			break;
		}
	}
	if(check)
	{
		int bdir = (dir + 2) % 4;
		int nx = x + dx[bdir];
		int ny = y + dy[bdir];
		if(!a[nx][ny]) solve(nx,ny,dir);

	}
}

int main()
{
	cin>>n>>m>>x>>y>>dir;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	solve(x,y,dir);
	cout<<sol;
	return 0;
}
