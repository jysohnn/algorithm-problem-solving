#include <cstdio>

int t,n;
int a[101];
long long sol = 0;

long long gcd(int x, int y)
{
	if(y == 0) return x;
	else return gcd(y, x % y);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		sol = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",a+i);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++) sol += gcd(a[i],a[j]);
		printf("%lld\n",sol);
	}
	return 0;
}