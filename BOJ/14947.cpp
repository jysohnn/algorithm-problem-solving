#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;

const int block[3][3][3] = { { {0,0,0},{0,1,0},{0,0,0} },
					  { {0,1,0},{0,1,0},{0,1,0} },
					  { {0,0,0},{1,1,1},{0,0,0} } };
const int dx[3][4] = { { -2,2,0,0 },{ -2,2,0,0 },{ -1,1,0,0 } };
const int dy[3][4] = { { 0,0,-2,2 },{ 0,0,-1,1 },{ 0,0,-2,2 } };
const int rule[3][4] = { {1,1,2,2},{0,0,1,1},{2,2,0,0} };

ll n, m, sx, sy, ex, ey, sol = 9999999999;
ll a[501][501], d[3][501][501];
bool v[3][501][501] = { 0 };

bool bbc(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }
bool bc(ll s, ll x, ll y)
{
	bool ret = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (block[s][i][j] && !bbc(x + i - 1, y + j - 1)) return 0;
	if (s == 0 && !a[x][y]) return 0;
	if (s == 1 && !(a[x][y] || (a[x - 1][y] && a[x + 1][y]))) return 0;
	if (s == 2 && !(a[x][y] || (a[x][y - 1] && a[x][y + 1]))) return 0;
	return 1;
}
bool goal(ll s, ll x, ll y)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (block[s][i][j] && x + i - 1 == ex && y + j - 1 == ey) return 1;
	return 0;
}

void bfs()
{
	queue<tll> q;
	v[0][sx][sy] = 1; d[0][sx][sy] = 0;
	q.push(tll(0, sx, sy));
	while (!q.empty())
	{
		tll p = q.front(); q.pop();
		ll s = get<0>(p), x = get<1>(p), y = get<2>(p);
		if (goal(s, x, y)) sol = min(sol, d[s][x][y]);

		for (int i = 0; i < 4; i++)
		{
			ll nx = x + dx[s][i], ny = y + dy[s][i], ns = rule[s][i];
			ll nd = d[s][x][y] + 1;
			if (bc(ns, nx, ny) && !v[ns][nx][ny])
				v[ns][nx][ny] = 1, d[ns][nx][ny] = nd, q.push(tll(ns, nx, ny));
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%1lld", &a[i][j]);
			if (a[i][j] == 2) sx = i, sy = j, a[i][j] = 1;
			if (a[i][j] == 3) ex = i, ey = j, a[i][j] = 1;
		}
	bfs();
	if (sol >= 9999999998) cout << "-2";
	else cout << sol;
	return 0;
}