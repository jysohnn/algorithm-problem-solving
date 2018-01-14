#include <cstdio>

long long n, f;

int main()
{
	long long i;
	scanf("%lld %lld",&n,&f);
	for(i = (n/100)*100; i<(n/100)*100+100;i++)
		if(i % f == 0) break;
	i %= 100;
	if(i < 10) putchar('0'), printf("%lld",i);
	else printf("%lld",i);
	return 0;
}