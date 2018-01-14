#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, m, k;
int a[1001];

int main()
{
	bool sol = 0; int s = 0;
	cin >> n >> m >> k; k *= m;
	for (int i = 0; i < n; i++) scanf("%d",a+i);
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		k -= a[i]; s++;
		if (k <= 0)
		{
			sol = 1; break;
		}
	}
	if (sol) printf("%d", s);
	else printf("STRESS");
	return 0;
}