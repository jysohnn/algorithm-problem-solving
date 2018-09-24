#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, a[302];
int dp[302][2];

int solve(int x, int y)
{
	if(dp[x][y] != -1) return dp[x][y];
	if(x == 0) return dp[x][y] = 0;
	if(x == 1) return dp[x][y] = a[x];
	if(y == 1) return dp[x][y] = solve(x-1,0) + a[x];
	else return dp[x][y] = max(solve(x-2, 1), solve(x-2, 0)) + a[x];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d",&n); a[0] = 0;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	printf("%d",max(solve(n,0), solve(n,1)));
	return 0;
}