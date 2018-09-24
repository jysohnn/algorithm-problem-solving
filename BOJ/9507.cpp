#include <cstdio>

long long p[68] = {1,1,2,4};

int main()
{
	int t;
	for(int i=4;i<68;i++) p[i] = p[i-1]+p[i-2]+p[i-3]+p[i-4];
	scanf("%d",&t);
	while(t--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",p[x]);
	}
	return 0;
}