#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int t, n;
pll dp[1001][1001];
ll a[1001];

pll solve(int s, int e)
{
	if (dp[s][e].first != -1) return dp[s][e];
	if (s == e) return dp[s][e] = pll(a[s], 0);

	pll l = solve(s + 1, e), r = solve(s, e - 1);
	if (l.second + a[s] > r.second + a[e]) dp[s][e] = pll(l.second + a[s], l.first);
	else if (l.second + a[s] < r.second + a[e]) dp[s][e] = pll(r.second + a[e], r.first);
	else if (l.first < r.first) dp[s][e] = pll(l.second + a[s], l.first);
	else dp[s][e] = pll(r.second + a[e], r.first);
	
	return dp[s][e];
}

int main()
{
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld", a + i);
		printf("%lld\n", solve(0, n - 1).first);
	}
	return 0;
}