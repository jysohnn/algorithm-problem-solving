#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll n, m;
bool man[1001] = { 0 };
bool visit[1001] = { 0 };
vector<pll> adj[1001];


ll prim()
{
	priority_queue<pll, vector<pll>, greater<pll> > q;
	int count = 0; int ret = 0;

	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int x = q.top().second;
		visit[x] = 1; ret += q.top().first; q.pop(); count++;
		for (int i = 0; i < adj[x].size(); i++) q.push(adj[x][i]);
		while (!q.empty() && visit[q.top().second]) q.pop();
	}
	if (count != n) return -1;
	else return ret;
}

int main()
{
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		string str; cin >> str;
		if (str == string("M")) man[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		ll x, y, cost; scanf("%lld %lld %lld", &x, &y, &cost);
		x--; y--;
		if (man[x] == man[y]) continue;
		adj[x].push_back(make_pair(cost, y));
		adj[y].push_back(make_pair(cost, x));
	}
	cout << prim();
	return 0;
}