#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int> > vec;
int a[301][301] = { 0 };
bool v[301][301] = { 0 };
int n, m;
int x, y, xx, yy;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

bool bc(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

void dfs(int x, int y)
{
	v[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (bc(nx,ny) && !v[nx][ny])
		{
			if (a[nx][ny])
			{
				v[nx][ny] = 1;
				vec.push_back(pair<int, int>(nx, ny));
			}
			else dfs(nx, ny);
		}
	}
}

int main()
{
	int sol;
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d",&x,&y,&xx,&yy);
	x--, y--, xx--, yy--;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c = getchar();
			if (c == '1') a[i][j] = 1;
			else if (c == '0') a[i][j] = 0;
			else if (c == '#') a[i][j] = 2;
			else a[i][j] = 3;
		}
		getchar();
	}
	for (sol = 1; 1; sol++)
	{
		for (int i = 0; i < 301; i++)
			for (int j = 0; j < 301;j++) v[i][j] = 0;
		dfs(x,y);
		while(!vec.empty())
		{
			pair<int, int> p = vec.back();
			vec.pop_back();
			if (p.first == xx && p.second == yy)
			{
				printf("%d", sol);
				return 0;
			}
			a[p.first][p.second] = 0;
		}
	}
	return 0;
}