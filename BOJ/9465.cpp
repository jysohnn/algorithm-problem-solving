#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, n;
int a[100001][2];
int dp[100001][2];

int main()
{
	cin >> t;
	while (t--)
	{
		int sol = 0;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++) scanf("%d", &a[i][j]);
		dp[0][0] = a[0][0]; dp[0][1] = a[0][1];
		dp[1][0] = a[1][0] + dp[0][1]; dp[1][1] = a[1][1] + dp[0][0];
		for (int i = 2; i < n; i++)
			dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + a[i][0], 
			dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + a[i][1];
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++) sol = max(sol, dp[i][j]);
		cout << sol << '\n';
	}
	return 0;
}