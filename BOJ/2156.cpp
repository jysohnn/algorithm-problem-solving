#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[10001] = { 0 };
int dp[10001][2];

int main()
{
	int sol = 0;
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	dp[0][0] = a[0], dp[0][1] = a[0];
	dp[1][0] = a[1], dp[1][1] = a[0] + a[1];
	dp[2][0] = a[0] + a[2], dp[2][1] = a[1] + a[2];
	for (int i = 3; i < n; i++)
		dp[i][1] = dp[i - 1][0] + a[i],
		dp[i][0] = max(max(dp[i - 2][0], dp[i - 2][1]), max(dp[i - 3][0], dp[i - 3][1])) + a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++) sol = max(sol, dp[i][j]);
	cout << sol;
	return 0;
}