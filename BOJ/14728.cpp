#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
pll a[101];
ll dp[10001] ={ 0 };
ll n, k, sol = 0;

int main()
{
	scanf("%lld %lld", &n, &k);
	for(int i = 0; i < n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 10001; j >= 0; j--)
			if(j + a[i].first < 10001)
				dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second);
	}
	for(int i = 0; i <= k; i++) sol = max(sol, dp[i]);
	printf("%d", sol);
	return 0;
}