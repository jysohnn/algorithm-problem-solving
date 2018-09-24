#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[101][11];

long long solve(int x, int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 0 && y == 0) return dp[x][y] = 0;
	else if (x == 0) return dp[x][y] = 1;

	long long ret = 0;
	if (y > 0) ret += solve(x - 1, y - 1);
	if (y < 9) ret += solve(x - 1, y + 1);

	return dp[x][y] = (ret % 1000000000);
}

int main()
{
	long long sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i <= 9; i++) sol += solve(n - 1, i), sol %= 1000000000;
	cout << sol;
	return 0;
}