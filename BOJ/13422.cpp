#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int a[100001], sol = 0;
		long long n, m, k, sum = 0;
		scanf("%lld %lld %lld", &n, &m, &k);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 0; i < m; i++) sum += a[i];
		if (sum < k) sol++;
		if (n == m) { printf("%d\n", sol); continue; }
		for (int i = 1; i < n; i++)
		{
			sum -= a[i - 1];
			sum += a[(i + m - 1) % n];
			if (sum < k) sol++;
		}
		printf("%d\n",sol);
	}
	return 0;
}