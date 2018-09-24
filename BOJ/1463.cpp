#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[1000001];

int solve(int x)
{
	if (dp[x] != -1) return dp[x];
	if (x == 1) return dp[x] = 0;
	int ret = 9999999;
	if (x % 3 == 0) ret = min(ret, solve(x / 3) + 1);
	if (x % 2 == 0) ret = min(ret, solve(x / 2) + 1);
	ret = min(ret, solve(x - 1) + 1);
	return dp[x] = ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << solve(n);
	return 0;
}