#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

ll m, n;
ll a[1001][1001];
ll d[1001][1001];

ll solve(ll x, ll y)
{
	if (d[x][y] != -1) return d[x][y];
	if (x == 0 && y == 0) return d[x][y] = a[x][y];
	if (x == 0) return d[x][y] = a[x][y] + solve(x, y - 1);
	if (y == 0) return d[x][y] = a[x][y] + solve(x - 1, y);

	return d[x][y] = max({ solve(x, y - 1), solve(x - 1, y), solve(x - 1, y - 1) }) + a[x][y];
}

int main()
{
	memset(d, -1, sizeof(d));
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) scanf("%lld", &a[i][j]);
	cout << solve(m - 1, n - 1);
	return 0;
}