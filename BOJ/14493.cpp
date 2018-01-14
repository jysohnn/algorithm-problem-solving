#include <cstdio>

struct bot
{
	int d;
	int r;
} x[50001];

int n;

int main()
{
	int i, t;
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d",&a,&b);
		x[i].d = a + b;
		x[i].r = b;
	}
	i = 0, t = 0;
	for (i=0;i<n;i++)
	{
		if (t % x[i].d > x[i].r) t++;
		else t += x[i].r - t % x[i].d + 1;
	}
	printf("%d",t);
	return 0;
}