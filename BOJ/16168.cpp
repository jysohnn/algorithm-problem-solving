#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <functional>
#include <map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m, odd = 0;
ll a[3002] = { 0 };
bool v[3002] = { 0 };
vector<ll> adj[3002];

void dfs(ll x)
{
	v[x] = 1;
	for (ll i = 0; i < adj[x].size(); i++)
		if (!v[adj[x][i]]) dfs(adj[x][i]);
}

int main()
{
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < m; i++)
	{
		ll x, y; scanf("%lld %lld", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		a[x]++;
		a[y]++;
	}

	ll count = 0;
	for (ll i = 1; i <= n; i++)
		if (!v[i]) dfs(i), count++;

	if (count != 1)
	{
		printf("NO");
		return 0;
	}

	for (ll i = 1; i <= n; i++)
		if (a[i] % 2 == 1) odd++;
	if (odd == 2 || odd == 0) printf("YES");
	else printf("NO");
	return 0;
}