#include <cstdio>

int n, m, k;
long long a[4000001] = { 0 };
long long lazy[4000001] = { 0 };

void update(int n, int s, int e, int l, int r, long long v)
{
	if (lazy[n])
	{
		a[n] += (e - s + 1) * lazy[n];
		if (s != e) lazy[n * 2] += lazy[n], lazy[n * 2 + 1] += lazy[n];
		lazy[n] = 0;
	}

	if (s > r || e < l) return;
	else if (l <= s && e <= r)
	{
		a[n] += (e - s + 1) * v;
		if (s != e) lazy[n * 2] += v, lazy[n * 2 + 1] += v;
	}
	else
	{
		update(n * 2, s, (s + e) / 2, l, r, v);
		update(n * 2 + 1, (s + e) / 2 + 1, e, l, r, v);
		a[n] = a[n * 2] + a[n * 2 + 1];
	}
}
long long sum(int n, int s, int e, int l, int r)
{

	if (lazy[n])
	{
		a[n] += (e - s + 1) * lazy[n];
		if (s != e) lazy[n * 2] += lazy[n], lazy[n * 2 + 1] += lazy[n];
		lazy[n] = 0;
	}

	if (s > r || e < l) return 0;
	else if (l <= s && e <= r) return a[n];
	else return sum(n * 2, s, (s + e) / 2, l, r) + sum(n * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		long long x;
		scanf("%lld", &x);
		update(1, 1, n, i, i, x);
	}
	for (int i = 0; i < m + k; i++)
	{
		int q;
		long long x, y, z;
		scanf("%d", &q);
		if (q == 1)
		{
			scanf("%lld %lld %lld", &x, &y, &z);
			update(1, 1, n, x, y, z);
		}
		else
		{
			scanf("%lld %lld", &x, &y);
			printf("%lld\n", sum(1, 1, n, x, y));
		}
	}
	return 0;
}