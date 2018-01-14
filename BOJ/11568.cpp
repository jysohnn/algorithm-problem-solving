#include <cstdio>

int n;
long long a[1001];
long long d[1001];
long long sol = 0;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",a+i);
	d[0] = 1;
	for(int i=1;i<n;i++)
	{
		int max = 1;
		for(int j=i-1;j>=0;j--)
			if(a[j] < a[i] && max < d[j] + 1) max = d[j] + 1;
			d[i] = max;
	}
	for(int i=0;i<n;i++)
		if(sol < d[i]) sol = d[i];
	printf("%lld",sol);
	return 0;
}