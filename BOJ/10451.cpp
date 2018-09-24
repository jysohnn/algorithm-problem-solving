#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll t;

int main()
{
	cin >> t;
	while (t--)
	{
		int a[1001], sol = 0;
		bool visit[1001] = { 0 };

		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
			if (!visit[i])
			{
				int p = a[i]; visit[p] = 1;
				while (p != i) p = a[p], visit[p] = 1;
				sol++;
			}
		printf("%d\n", sol);
	}
	return 0;
}