#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		long long sol = 0;
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
		{
			int a, b, c, tmp;
			scanf("%d %d %d", &a, &b, &c);
			tmp = max(a, max(b, c));
			if (tmp > 0) sol += tmp;
		}
		printf("%lld\n",sol);
	}
	return 0;
}