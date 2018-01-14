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
	int ret = 0;
	for (int i = 0; i < x; i++)
		if (a[i] < a[x]) ret = max(ret, solve(i));
	return dp[x] = ret + a[x];
}

int main()
{
	int sol = 0;
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i); 
	a[n] = 1001;
	cout << solve(n) - 1001;
	return 0;
}