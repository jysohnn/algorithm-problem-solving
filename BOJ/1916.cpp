#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;

vector < pii > adj[1001];
int dis[1001];
bool visit[1001] = { 0 };

void dijk(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	dis[s] = 0;
	q.push(make_pair(0, s));
	while (!q.empty())
	{
		while (!q.empty() && visit[q.top().second]) q.pop();
		if (q.empty()) break;
		int next = q.top().second; q.pop();
		visit[next] = 1;
		for (int i = 0; i < adj[next].size(); i++)
			if (dis[adj[next][i].first] == -1 || dis[adj[next][i].first] > dis[next] + adj[next][i].second)
			{
				dis[adj[next][i].first] = dis[next] + adj[next][i].second;
				q.push(make_pair(dis[adj[next][i].first], adj[next][i].first));
			}
	}
}

int main()
{
	int s, e;
	memset(dis, -1, sizeof(dis));
	scanf("%d %d",&n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		scanf("%d %d %d", &x, &y, &cost); x--; y--;
		adj[x].push_back(make_pair(y, cost));
	}
	cin >> s >> e; s--; e--;
	dijk(s);
	cout << dis[e];
	return 0;
}