#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int t, n, m;
vector<pii> cost[20001];
int val[20001], to[20001], dp[20001];

int dfs(int x)
{
	if (dp[x] != -1) return dp[x];

	dp[x] = val[x];
	for (int i = 0; i < cost[x].size(); i++)
	{
		int next = cost[x][i].first;
		int c = cost[x][i].second;

		if (dp[x] < val[x] + dfs(next) - c) dp[x] = val[x] + dfs(next) - c, to[x] = next;
	}
	return dp[x];
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int idx = 0;
		for (int i = 0; i < 20001; i++) cost[i].clear();
		memset(val, 0, sizeof(val));
		memset(dp, -1, sizeof(dp));
		memset(to, -1, sizeof(to));

		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", val + i);
		for (int i = 0; i < m; i++)
		{
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c); x--; y--;
			cost[x].push_back(pii(y, c));
		}
		
		dfs(0);
		
		vector<int> path;
		while (idx != -1)
		{
			path.push_back(idx + 1);
			idx = to[idx];
		}
		printf("%d %d\n", dp[0], path.size());
		for (auto i = path.begin(); i != path.end(); i++) printf("%d ", *i);
		putchar('\n');
	}
	return 0;
}