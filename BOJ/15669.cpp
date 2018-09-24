#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

ll n, m;
ll dp[100001][2];
ll p[100001];
vector<ll> adj[100001];
ll is_even[100001] = { 0 };

ll solve(ll x, ll y, ll parent)
{
	ll ret = 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (parent != -1)
	{
		if (is_even[parent]) is_even[x] = 0;
		else is_even[x] = 1;
	}
	else is_even[x] = 1;

	p[x] = parent;

	if (y)
	{
		for (ll i = 0; i < adj[x].size(); i++)
			if(adj[x][i] != parent)
				ret += solve(adj[x][i], 0, x);
	}
	else
	{
		ret++;
		for (ll i = 0; i < adj[x].size(); i++)
			if (adj[x][i] != parent)
				ret += solve(adj[x][i], 1, x);
	}
	return dp[x][y] = ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(p, -1, sizeof(p));
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n - 1; i++)
	{
		ll x, y; scanf("%lld %lld", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	solve(0, 0, -1);
	solve(0, 1, -1);
	
	for (ll i = 0; i < m; i++)
	{
		ll sol = 0, even, odd;
		ll x, y, z; scanf("%lld %lld %lld", &x, &y, &z);
		x--; y--;

		if (p[y] == x) swap(x, y);
		if (is_even[x]) odd = dp[0][1], even = dp[0][0];
		else odd = dp[0][0], even = dp[0][1];

		if (z)
		{
			sol += dp[x][0] * (odd - dp[x][1]);
			sol += dp[x][1] * (even - dp[x][0]);
		}
		else
		{
			sol += dp[x][0] * (even - dp[x][0]);
			sol += dp[x][1] * (odd - dp[x][1]);
		}
		printf("%lld\n", sol);
	}
	return 0;
}