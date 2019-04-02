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

ll n, last;
ll a[65][65];
ll idx[65][65];
bool v[65 * 65] = { 0 };
vector<ll> adj[65 * 65];

bool bc(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < n; }

bool dfs(ll x)
{
	bool ret = 0;
	v[x] = 1;
	if (x == last) return 1;
	for (ll i = 0; i < adj[x].size(); i++)
		if (!v[adj[x][i]]) ret |= dfs(adj[x][i]);
	return ret;
}

int main()
{
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++) scanf("%lld", &a[i][j]);
	ll tmp = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
		{
			if (i == n - 1 && j == n - 1) last = tmp;
			idx[i][j] = tmp++;
		}
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
		{
			if (a[i][j] == -1) continue;
			if (bc(i + a[i][j], j))
			{
				adj[idx[i][j]].push_back(idx[i + a[i][j]][j]);
			}
			if (bc(i, j + a[i][j]))
			{
				adj[idx[i][j]].push_back(idx[i][j + a[i][j]]);
			}
		}
	if (dfs(0)) printf("HaruHaru");
	else printf("Hing");
	return 0;
}