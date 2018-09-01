#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
using db = double;

int t;
int h, c;
db a[201];
db dp[201][201][201];

db solve(int n, int x, int y)
{
	db ret;
	if (dp[n][x][y] != -1) return dp[n][x][y];
	if (n)
	{
		ret = 99999999999.0;
		for (int i = x + 1; i < y; i++)
			ret = min(ret, solve(n - 1, x, i) + solve(0, i, y));
		return dp[n][x][y] = ret;
	}
	else
	{
		ret = 0.0;
		for (int i = x + 1; i < y; i++)
			ret += abs(a[x] + (a[y] - a[x]) * ((db)i - (db)x) / ((db)y - (db)x) - a[i]);
		return dp[n][x][y] = ret;
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 201; i++)
			for (int j = 0; j < 201; j++)
				for (int k = 0; k < 201; k++) dp[i][j][k] = -1;

		scanf("%d %d", &h, &c);
		for (int i = 0; i < h; i++) scanf("%lf", a + i);
		printf("%.4lf\n", solve(c - 2, 0, h - 1) / (db)h);
	}
	return 0;
}