#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, l, k; 
ll dp[32][32];

ll solve(ll x, ll y)
{
	if(x < y) y = x;
	if(x < 0 || y < 0) return 0;
	if(y == 0) return dp[x][y] = 1;
	if(dp[x][y] != -1) return dp[x][y];

	return dp[x][y] = solve(x-1, y-1) + solve(x-1, y);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[1][0] = 1;
	dp[1][1] = 2;
	cin >> n >> l >> k;

	k = solve(n, l) - k + 1;
		
	while(n)
	{
		if(k <= solve(n-1, l-1))
		{
			printf("1");
			n--; l--;
		}
		else
		{
			printf("0");
			k -= solve(n-1, l-1);
			n--;
		}
	}
	return 0;
}
