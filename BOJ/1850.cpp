#include <cstdio>

long long x, y;

long long gcd(long long x, long long y)
{
	if (x % y == 0) return y;
	else return gcd(y, x%y);
}

int main()
{
	scanf("%lld %lld",&x,&y);
	for (long long i = 0; i < gcd(x, y); i++) putchar('1');
	return 0;
}