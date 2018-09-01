#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int h, w;
int m[51][51];
bool v[51][51];
const int dx[8] = { 0,0,1,1,1,-1,-1,-1 };
const int dy[8] = { 1,-1,0,1,-1,0,1,-1 };

bool bc(int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; }

void dfs(int x, int y)
{
	v[x][y] = 1;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (bc(nx, ny) && !v[nx][ny] && m[nx][ny]) dfs(x + dx[i], y + dy[i]);
	}
		
}

int main()
{
	while (1)
	{
		int sol = 0;
		memset(v, 0, sizeof(v));
		scanf("%d %d", &w, &h);
		if (!h && !w) break;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) scanf("%d", &m[i][j]);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if (!v[i][j] && m[i][j]) dfs(i, j), sol++;
		printf("%d\n", sol);
	}
	return 0;
}