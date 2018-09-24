#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int t;
vector<pair<int, int> > adj[1001];
bool visit[1001];

int solve(int x)
{
	int ret = 0;
	visit[x] = 1;
	if (x != 0 && adj[x].size() == 1) return adj[x][0].second;
	for (int i = 0; i < adj[x].size(); i++)
	{
		pair<int, int> tmp = adj[x][i];
		if(!visit[tmp.first]) ret += min(tmp.second, solve(tmp.first));
	}
	return ret;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		for (int i = 0; i < 1001; i++) adj[i].clear();
		memset(visit, 0, sizeof(visit));
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int x, y, k;
			scanf("%d %d %d", &x, &y, &k); x--; y--;
			adj[x].push_back(make_pair(y, k));
			adj[y].push_back(make_pair(x, k));
		}
		printf("%d\n", solve(0));
	}
	return 0;
}