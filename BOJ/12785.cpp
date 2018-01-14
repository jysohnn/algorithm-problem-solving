#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll dp[201][201];
ll a, b, c, d;

ll solve(ll x, ll y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0 && y == 0) return dp[x][y] = 1;
	else if (x == 0) return dp[x][y] = 1;
	else if (y == 0) return dp[x][y] = 1;

	return dp[x][y] = (solve(x - 1, y) + solve(x, y - 1)) % 1000007;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> c >> d >> a >> b;
	c -= a; d -= b;
	a--; b--;
	solve(a, b);
	solve(c, d);
	printf("%lld", (dp[a][b] * dp[c][d]) % 1000007);
	return 0;
}