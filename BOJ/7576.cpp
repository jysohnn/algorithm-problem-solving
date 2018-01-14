#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

ll m, n;
ll a[1001][1001], d[1001][1001];
ll to = 0, sol = -1;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };
queue<pll> q;

bool bc(ll x, ll y) { return x >= 0 && x < m && y >= 0 && y < n; }

void bfs()
{
	while (!q.empty())
	{
		pll p = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			ll nx = p.first + dx[i];
			ll ny = p.second + dy[i];
			if (bc(nx, ny) && !a[nx][ny])
			{
				a[nx][ny] = 1; d[nx][ny] = d[p.first][p.second] + 1;
				to--;
				if (to == 0) sol = d[p.first][p.second] + 1;
				q.push(pll(nx, ny));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", &a[i][j]);
			if (!a[i][j]) to++;
			if (a[i][j] == 1) q.push(pll(i, j)), d[i][j] = 0;
		}
	if (to == 0) { cout << "0"; return 0; }
	bfs(); cout << sol;
	return 0;
}