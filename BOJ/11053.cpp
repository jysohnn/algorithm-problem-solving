#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[1001];
int a[1001];

int solve(int x)
{
	if (dp[x] != -1) return dp[x];
	int ret = 1;
	for (int i = 0; i < x; i++)
		if (a[i] < a[x]) ret = max(ret, solve(i) + 1);
	return dp[x] = ret;
}

int main()
{
	int sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i); 
	a[n] = 999999;
	cout << solve(n) - 1;
	return 0;
}