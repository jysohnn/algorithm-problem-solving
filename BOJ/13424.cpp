#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int t, n, m, k;
vector<pii> adj[101];
int dis[101][101]; // start, end
bool visit[101];

void dijk(int s, int k)
{
	priority_queue<pii, vector<pii>, greater<pii> > q;
	
	dis[k][s] = 0;
	q.push(make_pair(0, s));

	while (!q.empty())
	{
		while (!q.empty() && visit[q.top().second]) q.pop();
		if (q.empty()) break;
		int p = q.top().second;
		q.pop();
		visit[p] = 1;
		for (int i = 0; i < adj[p].size(); i++)
		{
			if (dis[k][adj[p][i].second] > adj[p][i].first + dis[k][p])
				dis[k][adj[p][i].second] = adj[p][i].first + dis[k][p];
			q.push(make_pair(dis[k][adj[p][i].second], adj[p][i].second));
		}
	}
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int sol = 9999999, idx = 0;
		for (int i = 0; i < 101; i++) adj[i].clear();
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++) dis[i][j] = 9999999;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w); x--, y--;
			adj[x].push_back(make_pair(w, y));
			adj[y].push_back(make_pair(w, x));
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			int s;
			memset(visit, 0, sizeof(visit));
			scanf("%d", &s); s--;
			dijk(s, i);
		}
		for (int i = n-1; i >= 0; i--)
		{
			int sum = 0;
			for (int j = 0; j < k; j++) sum += dis[j][i];
			if (sum <= sol) idx = i, sol = sum;
		}
		printf("%d\n",idx+1);
	}
	return 0;
}