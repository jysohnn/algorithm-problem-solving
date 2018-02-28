#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

ll t, n, k;
ll a[21];
ll dp[10001];

int main()
{
	cin >> t;
	while (t--)
	{
		scanf("%lld", &n);
		for (int i = 0; i < n; i++) scanf("%lld", a + i);
		scanf("%lld", &k);

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
		{
			dp[a[i]]++;
			for (int j = 0; j <= k; j++)
				if (j - a[i] >= 0) dp[j] += dp[j - a[i]];
		}
		printf("%lld\n", dp[k]);
	}
	return 0;
}