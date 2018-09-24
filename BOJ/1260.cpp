#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int N = 1001;
bool visit[N];
vector<int> adj[N];

void dfs1(int x) {
	visit[x] = 1;
	printf("%d ", x + 1); // doing
	for (int i = 0; i < adj[x].size(); i++)
		if (!visit[adj[x][i]]) dfs1(adj[x][i]);
}

void dfs(int x) { // iterative

	stack<int> s, index;
	int p = x, idx = 0;
	do
	{
		int i, tmp = adj[p].size();
		if (!visit[p])
		{
			visit[p] = 1;
			printf("%d ", p + 1); // doing
		}
		for (i = idx; i < adj[p].size(); i++)
			if (!visit[adj[p][i]])
			{
				s.push(p); index.push(i);
				p = adj[p][i]; idx = 0; break;
			}
		if (i == tmp) p = s.top(), s.pop(), idx = index.top(), index.pop();
	} while (!s.empty());
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visit[x] = 1;
	while (!q.empty())
	{
		int p = q.front(); q.pop();
		printf("%d ", p + 1); // doing
		for (int i = 0; i < adj[p].size(); i++)
			if (!visit[adj[p][i]])
			{
				q.push(adj[p][i]);
				visit[adj[p][i]] = 1;
			}
	}
}

int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		int x, y; scanf("%d %d", &x, &y); x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < n; i++) sort(adj[i].begin(), adj[i].end());
	memset(visit, 0, sizeof(visit));
	dfs(--v); putchar('\n');
	memset(visit, 0, sizeof(visit));
	bfs(v); putchar('\n');
	return 0;
}