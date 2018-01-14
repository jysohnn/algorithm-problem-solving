#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[1001];
int dp[1001];

int solve(int x)
{
	if (dp[x] != -1) return dp[x];
	int ret = a[x];
	for (int i = 1; i < x; i++) ret = max(ret, solve(x - i) + solve(i));
	return dp[x] = ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	cout << solve(n);
	return 0;
}