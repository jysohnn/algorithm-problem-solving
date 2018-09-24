#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll t;
ll n, m, w;
vector<pll> adj[501];
ll dis[501];

bool bell(ll s)
{
	bool flag;

	dis[s] = 0;
	for(int i=0; i<adj[s].size(); i++)
		dis[adj[s][i].first] = adj[s][i].second;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			for(int k=0; k<adj[j].size(); k++)
			{
				ll next = adj[j][k].first;
				ll d = adj[j][k].second;
				if((dis[next] == -1 && dis[j] != -1) || dis[next] > dis[j] + d)
				{
					dis[next] = dis[j] + d;
					if(i == n-1) return 0;
				}
					
			}
	}
	return 1;
}

int main()
{
	scanf("%lld", &t);
	while(t--)
	{
		memset(dis, -1, sizeof(dis));
		for(int i=0; i<501; i++) adj[i].clear();
		scanf("%lld %lld %lld", &n, &m, &w);
		for(int i=0; i<m; i++)
		{
			ll x, y, c;
			scanf("%lld %lld %lld", &x, &y, &c); x--; y--;
			adj[x].push_back({ y, c });
			adj[y].push_back({ x, c });
		}
		for(int i=0; i<w; i++)
		{
			ll x, y, c;
			scanf("%lld %lld %lld", &x, &y, &c); x--; y--;
			adj[x].push_back({ y, -1 * c });
		}
		if(!bell(0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}