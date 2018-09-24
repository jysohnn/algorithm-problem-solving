#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, dp[1000001][2];
vector<ll> e[1000001];

ll solve(ll x, ll y, ll p)
{
	ll ret = 0;

	if (dp[x][y] != -1) return dp[x][y];
	if (y == 0) // early
	{
		for (int i = 0; i < e[x].size(); i++)
			if (e[x][i] != p) ret += min(solve(e[x][i], 1, x), solve(e[x][i], 0, x));
		return dp[x][y] = ret + 1;
	}
	else // not early
	{
		for (int i = 0; i < e[x].size(); i++)
			if (e[x][i] != p) ret += solve(e[x][i], 0, x);
		return dp[x][y] = ret;
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%lld", &n);
	for (int i = 0; i < n - 1; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	printf("%lld", min(solve(0, 0, -1), solve(0, 1, -1)));
	return 0;
}