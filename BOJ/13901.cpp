#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int r, c, k, x, y;
bool a[1001][1001] = { 0 };
bool visit[1001][1001] = { 0 };
int dir[4];
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

bool bc(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int main()
{
	cin >> r >> c >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d",&x,&y);
		a[x][y] = 1;
	}
	cin >> x >> y;
	for (int i = 0; i < 4; i++) scanf("%d",dir+i), dir[i]--;
	
	k = 0;
	while (1)
	{
		int i;
		visit[x][y] = 1;
		for (i = 0; i < 4; i++)
		{
			int nx = x + dx[dir[(k+i) % 4]];
			int ny = y + dy[dir[(k+i) % 4]];
			if (bc(nx, ny) && !visit[nx][ny] && !a[nx][ny])
			{
				x = nx, y = ny;
				k = k + i;
				break;
			}
		}
		if (i == 4) break;
	}
	printf("%d %d", x, y);
	return 0;
}