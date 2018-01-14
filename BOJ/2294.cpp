#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = 1000001;
int n, k;
int a[101];
int d[100001];
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= k; i++) d[i] = INF;
	d[0] = 0;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < n; j++)
			if (a[j] <= i) d[i] = min(d[i], 1 + d[i - a[j]]);
	if (d[k] != INF) printf("%d", d[k]);
	else printf("-1");
	return 0;
}