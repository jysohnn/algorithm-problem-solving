#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 10007;
int n;
int dp[1001][11];

long long solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0) return dp[x][y] = 1;

	long long ret = 0;
	for (int i = 0; i <= y; i++) ret += solve(x - 1, i), ret %= MOD;

	return dp[x][y] = ret;
}

int main()
{
	long long sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i <= 9; i++) sol += solve(n - 1, i), sol %= MOD;
	cout << sol;
	return 0;
}