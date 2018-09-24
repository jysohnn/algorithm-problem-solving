#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;

const ll INF = 1e18;
const ll N = 4001;
ll n, m;

ll dis[N], dis2[N*2];
bool visit[N], visit2[N*2];
vector<pll> adj[N], adj2[N*2];

void dijk(ll s) // adj : pair(vertex, cost)
{
	priority_queue<pll, vector<pll>, greater<pll> > q;
	dis[s] = 0;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		while (!q.empty() && visit[q.top().second]) q.pop();
		if (q.empty()) break;
		ll next = q.top().second; q.pop(); // q : pair(distance, vertex)
		visit[next] = 1;
		for (ll i = 0; i < adj[next].size(); i++)
			if (dis[adj[next][i].first] == -1 || dis[adj[next][i].first] > dis[next] + adj[next][i].second)
			{
				dis[adj[next][i].first] = dis[next] + adj[next][i].second;
				q.push(make_pair(dis[adj[next][i].first], adj[next][i].first));
			}
	}
}

void dijk2(ll s) // adj : pair(vertex, cost)
{
	priority_queue<pll, vector<pll>, greater<pll> > q;
	dis2[s] = 0;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		while (!q.empty() && visit2[q.top().second]) q.pop();
		if (q.empty()) break;
		ll next = q.top().second; q.pop(); // q : pair(distance, vertex)
		visit2[next] = 1;
		for (ll i = 0; i < adj2[next].size(); i++)
			if (dis2[adj2[next][i].first] == -1 || dis2[adj2[next][i].first] > dis2[next] + adj2[next][i].second)
			{
				dis2[adj2[next][i].first] = dis2[next] + adj2[next][i].second;
				q.push(make_pair(dis2[adj2[next][i].first], adj2[next][i].first));
			}
	}
}

int main()
{
    memset(dis, -1, sizeof(dis)); memset(dis2, -1, sizeof(dis2));
    memset(visit, 0, sizeof(visit)); memset(visit2, 0, sizeof(visit2));
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<m; i++)
    {
        ll x, y, d; scanf("%lld %lld %lld", &x, &y, &d);
        x--; y--; d *= 2;
        adj[x].push_back({y, d}); 
        adj[y].push_back({x, d});
		adj2[x].push_back({y+n, d/2});
		adj2[y].push_back({x+n, d/2});
		adj2[x+n].push_back({y, d*2});
		adj2[y+n].push_back({x, d*2});	
    }
    dijk(0);
	dijk2(0);

    ll sol = 0;
    for(ll i=0; i<n; i++)
	{
		if(dis2[i] == -1) dis2[i] = INF;
		if(dis2[i+n] == -1) dis2[i+n] = INF; 
        if(dis[i] == -1) dis[i] = INF;
		if(dis[i] < min(dis2[i], dis2[i+n])) sol++;
	}
    printf("%lld", sol);
    return 0;
}