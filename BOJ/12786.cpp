#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k;
bool p[101][21] = { 0 };
int dp[101][21];
const int INF = 5001;

int solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (!p[x][y]) return dp[x][y] = INF;
	if (x == 0)
	{
		if (y == 1 || y == 2) return dp[x][y] = 0;
		else return dp[x][y] = 1;
	}
	int ret = INF;
	for (int i = 1; i <= 20; i++)
		if(p[x-1][i]) ret = min(ret, solve(x - 1, i) + 1);
	if (p[x - 1][y]) ret = min(ret, solve(x - 1, y));
	if (y < 20 && p[x - 1][y + 1]) ret = min(ret, solve(x - 1, y + 1));
	if (y > 1 && p[x - 1][y - 1]) ret = min(ret, solve(x - 1, y - 1));
	if (y % 2 == 0 && p[x - 1][y/2]) ret = min(ret, solve(x - 1, y / 2));
	if (y == 20)
	{
		for (int i = 10; i <= 20; i++)
			if (p[x - 1][i]) ret = min(ret, solve(x - 1, i));
	}
	return dp[x][y] = ret;
}

int main()
{
	int sol = INF;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int m; scanf("%d",&m);
		for (int j = 0; j < m;j++)
		{
			int x; scanf("%d",&x);
			p[i][x] = 1;
		}
	}
	for (int i = 1; i <= 20; i++)
		if (p[n - 1][i]) sol = min(sol, solve(n - 1, i));
	if (sol > k) printf("-1");
	else printf("%d", sol);
	return 0;
}