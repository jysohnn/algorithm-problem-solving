#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long dp[91][2];

long long solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0 && y == 0) return dp[x][y] = 0;
	if (x == 0 && y == 1) return dp[x][y] = 1;
	if (y == 1) return dp[x][y] = solve(x - 1, 0);
	else return dp[x][y] = solve(x - 1, 0) + solve(x - 1, 1);
}

int main()
{
	long long sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	sol = solve(n - 1, 0) + solve(n - 1, 1);
	cout << sol;
	return 0;
}