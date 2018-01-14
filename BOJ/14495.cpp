#include <cstdio>

long long f[118] = { 0,1,1,1 };
int n;

int main()
{
	scanf("%d",&n);
	for (int i = 4; i < 118; i++) f[i] = f[i - 1] + f[i - 3];
	printf("%lld",f[n]);
	return 0;
}