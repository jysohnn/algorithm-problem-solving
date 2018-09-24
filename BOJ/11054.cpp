#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[1001][2];
int a[1001];

int solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	int ret = 1;
	if (y == 0)
	{
		for (int i = 0; i < x; i++)
			if (a[i] < a[x]) ret = max(ret, solve(i, 0) + 1);
	}
	else
	{
		for (int i = n - 1; i > x; i--)
			if (a[i] < a[x]) ret = max(ret, solve(i, 1) + 1);
	}
	return dp[x][y] = ret;
}

int main()
{
	int sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++) sol = max(sol, solve(i, 0) + solve(i, 1) - 1);
	cout << sol;
	return 0;
}