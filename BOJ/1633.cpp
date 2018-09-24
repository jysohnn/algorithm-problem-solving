#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <functional>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;

ll dp[1002][16][16];
pll a[1002];

ll solve(int k, int x, int y)
{
	if (k == -1) return 0;
	if (dp[k][x][y] != -1) return dp[k][x][y];
	if (x == 0 && y == 0) return dp[k][x][y] = 0;

	if (k >= 0 && k >= x + y)
		dp[k][x][y] = max(dp[k][x][y], solve(k - 1, x, y));
	if (k >= 0 && x - 1 >= 0)
		dp[k][x][y] = max(dp[k][x][y], solve(k - 1, x - 1, y) + a[k].first);
	if (k >= 0 && y - 1 >= 0)
		dp[k][x][y] = max(dp[k][x][y], solve(k - 1, x, y - 1) + a[k].second);

	return dp[k][x][y];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	ll x, y, n = 0;
	while (scanf("%lld %lld", &x, &y) != EOF)
		a[n].first = x, a[n].second = y, n++;
	cout << solve(n-1, 15, 15);
	return 0;
}