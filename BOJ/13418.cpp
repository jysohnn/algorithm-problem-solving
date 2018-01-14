#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
bool visit[1001];

int spanning(vector<pii>* adj)
{
	int ret = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		while (!q.empty() && visit[q.top().second]) q.pop();
		if (q.empty()) break;
		ret += q.top().first;
		int p = q.top().second;
		visit[p] = 1;
		for (int i = 0; i < adj[p].size(); i++)
			q.push(adj[p][i]);
	}
	return ret;
}

int main()
{
	vector<pii> adj[1001];
	vector<pii> adj2[1001];

	scanf("%d %d", &n, &m); n++; m++;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);

		if (w == 1) w = 0;
		else w = 1;

		adj[x].push_back(make_pair(-w, y));
		adj[y].push_back(make_pair(-w, x));
		adj2[x].push_back(make_pair(w, y));
		adj2[y].push_back(make_pair(w, x));
	}

	memset(visit, 0, sizeof(visit));
	int x = spanning(adj);
	memset(visit, 0, sizeof(visit));
	int y = spanning(adj2);
	printf("%d",x*x-y*y);
	return 0;
}