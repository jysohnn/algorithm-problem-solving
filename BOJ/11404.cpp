#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 101;
const int INF = 100000001;
typedef pair<int, int> pii;
vector<pii> adj[N];
int n, m;
int dis[N][N];

bool floyd()
{
	bool cycle = 0;
	memset(dis, INF, sizeof(dis));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, cost; scanf("%d %d %d", &x, &y, &cost);
		x--; y--;
		dis[x][y] = min(dis[x][y], cost);
	}
	for (int i = 0; i < n; i++) dis[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dis[i][j] > dis[i][k] + dis[k][j]) cycle = 1;
	return !cycle;
}

int main()
{
	floyd();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) printf("%d ", dis[i][j] >= INF ? 0 : dis[i][j]);
		putchar('\n');
	}
	return 0;
}