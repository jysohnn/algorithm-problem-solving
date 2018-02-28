#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> adj1[1001], adj2[1001];
ll n, m, p, sol = 0;
ll dis1[1001], dis2[1001];
bool v1[1001] = { 0 }, v2[1001] = { 0 };

void dijk(vector<pll>* adj, ll* dis, bool* v, ll src)
{
	priority_queue<pll, vector<pll>, greater<pll> > q;
	dis[src] = 0;
	q.push(pll(dis[src], src));
	while (!q.empty())
	{
		while (!q.empty() && v[q.top().second]) q.pop();
		if (q.empty()) break;
		pll tmp = q.top(); q.pop();
		ll cur = tmp.second, d = tmp.first;
		v[cur] = 1;
		for (int i = 0; i < adj[cur].size(); i++)
		{
			ll cost = adj[cur][i].first, tar = adj[cur][i].second;
			if (dis[tar] == -1 || dis[tar] > d + cost)
			{
				dis[tar] = d + cost;
				q.push(pll(dis[tar], tar));
			}
		}
	}
}

int main()
{
	memset(dis1, -1, sizeof(dis1));
	memset(dis2, -1, sizeof(dis2));
	cin >> n >> m >> p; p--;
	for (int i = 0; i < m; i++)
	{
		ll x, y, c;
		scanf("%lld %lld %lld", &x, &y, &c); x--; y--;
		adj1[x].push_back(pll(c, y));
		adj2[y].push_back(pll(c, x));
	}
	dijk(adj1, dis1, v1, p);
	dijk(adj2, dis2, v2, p);
	for (int i = 0; i < n; i++)
		if (dis1[i] + dis2[i] > sol) sol = dis1[i] + dis2[i];
	cout << sol;
	return 0;
}