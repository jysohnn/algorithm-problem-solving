#include <cstdio>

long long n[101]={0,1};

long long fibo(int x)
{
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(n[x] != 0) return n[x];
	else
	{
		n[x] = fibo(x-1) + fibo(x-2);
		return n[x];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",fibo(n));
	return 0;
}