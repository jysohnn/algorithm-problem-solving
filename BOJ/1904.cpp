#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

ll MOD = 15746;
ll n, dp[1000001];

ll solve(ll x)
{
	if (dp[x] != -1) return dp[x];
	if (x < 0) return 0;
	if (x == 0) return dp[x] = 1;
	if (x == 1) return dp[x] = 1;

	return dp[x] = (solve(x - 1) + solve(x - 2)) % MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << solve(n);
	return 0;
}