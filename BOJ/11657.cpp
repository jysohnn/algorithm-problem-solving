#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 501;
const int INF = 5000001;
typedef pair<int, int> pii;
vector<pii> adj[N];
int n, m;
int dis[N];

int bellman(int x)
{
	bool cycle = 0;
	dis[x] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < adj[j].size(); k++)
			{
				int next = adj[j][k].first;
				int cost = adj[j][k].second;
				if (dis[j] != INF && dis[next] > dis[j] + cost)
				{
					dis[next] = dis[j] + cost;
					if (i == n - 1) cycle = 1;
				}
			}
		}
	if (cycle) return 0;
	else return 1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, cost; scanf("%d %d %d",&x,&y,&cost);
		x--; y--;
		adj[x].push_back(pii(y, cost));
	}
	memset(dis, INF, sizeof(dis));
	if (bellman(0))
		for (int i = 1; i < n; i++) 
			printf("%d\n", dis[i] >= INF ? -1 : dis[i]);
	else printf("-1");
	return 0;
}