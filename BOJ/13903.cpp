#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<pair<int,int>, int> pii;

int r, c, n;
int a[1001][1001];
int d[1001][1001];
int dx[11], dy[11];
int visit[1001][1001];
int sol = 9999999;
queue<pii> q;

bool bc(int x, int y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int bfs()
{
	while (!q.empty())
	{
		pii p = q.front(); q.pop();
		if (p.first.first == r-1) return p.second;
		for (int i = 0; i < n; i++)
		{
			int nx = p.first.first + dx[i];
			int ny = p.first.second + dy[i];
			if (bc(nx, ny) && a[nx][ny] && !visit[nx][ny])
			{
				visit[nx][ny] = 1;
				q.push({ { nx,ny }, p.second + 1 });
			}
		}
	}
	return 9999999;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d %d", dx + i, dy + i);
	for (int i = 0; i < c; i++)
		if (a[0][i])
		{
			q.push({ { 0,i }, 0 });
			visit[0][i] = 1;
		}
	sol = bfs();
	if (sol >= 9999999) cout << "-1";
	else cout << sol;
	return 0;
}