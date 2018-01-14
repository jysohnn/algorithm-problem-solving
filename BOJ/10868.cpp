#include <cstdio>
#include <algorithm>
#define INF 1000000001

using namespace std;

int n, m;
long long a[400001];

void update(int n, int s, int e, int p, long long v)
{
	if (s > p || e < p) return;
	else if (s == e) a[n] = v;
	else
	{
		update(n * 2, s, (s + e) / 2, p, v);
		update(n * 2 + 1, (s + e) / 2 + 1, e, p, v);
		a[n] = min(a[n * 2] ,a[n * 2 + 1]);
	}
}
long long mini(int n, int s, int e, int l, int r)
{
	if (s > r || e < l) return INF;
	else if (l <= s && e <= r) return a[n];
	else return min(mini(n * 2, s, (s + e) / 2, l, r), mini(n * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		long long x;
		scanf("%lld", &x);
		update(1, 1, n, i, x);
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", mini(1,1,n,x,y));
	}
	return 0;
}