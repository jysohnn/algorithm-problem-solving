#include <iostream>
#include <cstring>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
int n, m, s, e;
vector<pii> adj[501];
vector<pii> p[501];
int dis[501];
bool visit[501];

void dijk(int s)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	dis[s] = 0;
	q.push(make_pair(0, s));
	while(!q.empty())
	{
		while(!q.empty() && visit[q.top().second]) q.pop();
		if(q.empty()) break;
		int next = q.top().second; q.pop();
		visit[next] = 1;
		for(int i = 0; i < adj[next].size(); i++)
		{
			if(dis[adj[next][i].first] == -1 || dis[adj[next][i].first] > dis[next] + adj[next][i].second)
			{
				p[adj[next][i].first] = p[next];
				p[adj[next][i].first].push_back(make_pair(next, adj[next][i].first));

				dis[adj[next][i].first] = dis[next] + adj[next][i].second;
				q.push(make_pair(dis[adj[next][i].first], adj[next][i].first));
			}
			else if(dis[adj[next][i].first] == dis[next] + adj[next][i].second)
			{
				for(int j=0; j < p[next].size(); j++) p[adj[next][i].first].push_back(p[next][j]);
				p[adj[next][i].first].push_back(make_pair(next, adj[next][i].first));
			}
		}
	}
}

int main()
{
	while(1)
	{
		for(int i=0; i<501; i++) adj[i].clear(), p[i].clear();
		memset(dis, -1, sizeof(dis));
		memset(visit, 0, sizeof(visit));

		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		scanf("%d %d", &s, &e);
		for(int i=0; i<m; i++)
		{
			int x, y, cost; scanf("%d %d %d", &x, &y, &cost);
			adj[x].push_back(make_pair(y, cost));
		}
		dijk(s);
		for(int i=0; i<p[e].size(); i++)
		{
			int from = p[e][i].first;
			int to = p[e][i].second;
			for(auto it = adj[from].begin(); it != adj[from].end(); it++)
				if(it->first == to) {adj[from].erase(it); break;}
		}
		memset(dis, -1, sizeof(dis));
		memset(visit, 0, sizeof(visit));
		dijk(s);
		printf("%d\n", dis[e]);
	}
	return 0;
}