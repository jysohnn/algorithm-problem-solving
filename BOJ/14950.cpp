#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, t;
bool visit[10001];
vector<pll> adj[10001];

ll mst()
{
	priority_queue<pll, vector<pll>, greater<pll> > q;
	ll count = 0, ret = 0, up = 0;

	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		ll x = q.top().second;
		visit[x] = 1; ret += (q.top().first + up); q.pop(); count++;
		if (x != 0) up += t;
		for (int i = 0; i < adj[x].size(); i++)
			q.push(pll(adj[x][i].second, adj[x][i].first));
		while (!q.empty() && visit[q.top().second]) q.pop();
	}
	if (count != n) return -1;
	else return ret;
}

int main()
{
	cin >> n >> m >> t;
	for (int i = 0; i < m; i++)
	{
		ll x, y, c;
		scanf("%lld %lld %lld", &x, &y, &c); x--; y--;
		adj[x].push_back(pll(y, c));
		adj[y].push_back(pll(x, c));
	}
	cout << mst();
}