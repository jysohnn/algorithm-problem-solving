#include <cstdio>

long long d[5001] = { 0 };
int t, n;

int main()
{
	d[0] = 1, d[2] = 1;
	for (int i = 4; i < 5001; i += 2)
	{
		for (int j = 2; j <= i; j++) d[i] += d[j - 2] * d[i - j], d[i] %= 1000000007;
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
	return 0;
}