#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll n, m;
ll p[100001][20];
ll d[100001];
bool v[100001];
vector<ll> adj[100001];

void make_tree(ll x, ll depth)
{
	v[x] = 1;
	d[x] = depth;
	for(int i=0; i<adj[x].size(); i++)
		if(!v[adj[x][i]])
		{
			p[adj[x][i]][0] = x;
			make_tree(adj[x][i], depth + 1);
		}
}

ll lca(ll x, ll y)
{
	if(d[x] > d[y]) swap(x, y);
	for(int i=19; i>=0; i--)
		if(d[y] - d[x] >= (1 << i)) y = p[y][i];
	if(x == y) return x;
	for(int i=19; i>=0; i--)
		if(p[x][i] != p[y][i])
		{
			x = p[x][i];
			y = p[y][i];
		}
	return p[x][0];
}

int main()
{
	scanf("%lld", &n);
	for(int i=0; i<n-1; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0; i<20; i++) p[1][i] = -1;
	make_tree(1, 0);

	for(int k=1; k<20; k++)
		for(int i=1; i<=n; i++)
			p[i][k] = p[p[i][k-1]][k-1];

	scanf("%lld", &m);
	for(int i=0; i<m; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		printf("%lld\n", lca(x, y));
	}
	return 0;
}