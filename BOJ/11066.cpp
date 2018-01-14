#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
int t, n;
int a[501], sum[502];
int dp[501][501];

ll solve(int s, int e)
{
	if (s == e) return dp[s][e] = 0;
	if (dp[s][e] != -1) return dp[s][e];

	ll ret = 9999999999999;
	for (int i = s+1; i <= e; i++) 
		ret = min(ret, solve(s, i - 1) + solve(i, e) + sum[e+1] - sum[s]);
	return dp[s][e] = ret;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d",&n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sum[0] = 0;
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
		printf("%lld\n", solve(0, n-1));
	}
	return 0;
}