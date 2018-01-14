#include <cstdio>
#include <queue>

using namespace std;

bool adj[1001][1001] = { 0 };
bool visit[1001] = { 0 };
int level[1001] = { 0 };
int s, e;
int n, m;
int sol = 999999;
queue<int> q;

void bfs()
{
	q.push(s);
	visit[s] = 1;
	level[s] = 0;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i=0;i<n;i++)
			if (!visit[i] && adj[p][i])
			{
				q.push(i);
				visit[i] = 1;
				level[i] = level[p] + 1;
			}
	}
};

int main()
{
	scanf("%d %d", &s, &e);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x - 1][y - 1] = 1;
		adj[y - 1][x - 1] = 1;
	}
	s--; e--;
	bfs();
	for (int i = 0; i < n; i++)
		if (!visit[i])
		{
			printf("-1");
			return 0;
		}
	printf("%d",level[e]);
	return 0;
}