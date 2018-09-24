#include <cstdio>

int main()
{
	long long x, y, p;
	scanf("%lld %lld %lld",&x,&y,&p);
	if (x + y >= 2*p) printf("%lld",x+y-2*p);
	else printf("%lld",x+y);
	return 0;
}