#include <cstdio>

long long n,a,b;

int main()
{
	scanf("%lld %lld %lld",&n,&a,&b);
	if(a <= 0 && b >= 0)
	{
		if(a % n != 0) a -= a%n;
		if(b % n != 0) b -= b%n;
	}
	else if(a >= 0 && b >= 0)
	{
		if(a % n != 0) a += n-a%n;
		if(b % n != 0) b -= b%n;
	}
	else
	{
		long long tmp = a;
		a = b;
		b = tmp;
		a *= -1, b *= -1;
		if(a % n != 0) a += n-a%n;
		if(b % n != 0) b -= b%n;
	}
	printf("%lld",b/n-a/n+1);
	return 0;
}