#include <cstdio>

int n, max = 0, sum = 0;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d",&x);
		sum += x;
		if (x > max) max = x;
	}
	printf("%d",sum-max);
	return 0;
}