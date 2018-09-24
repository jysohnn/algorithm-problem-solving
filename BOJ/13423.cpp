#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		long long n, a[1001], sol = 0;
		set<long long> s;

		scanf("%lld", &n);
		for (int i = 0; i < n; i++) scanf("%lld", a+i), s.insert(a[i]);
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (s.find(2 * a[i] - a[j]) != s.end()) sol++;
		printf("%lld\n",sol);
	}
	return 0;
}