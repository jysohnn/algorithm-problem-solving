#include <cstdio>
int main()
{
	int f[6];
	f[1]=1;
	for(int i=2;i<6;i++) f[i]=i*f[i-1];
	while(1)
	{
		int x,sol=0;
		scanf("%d",&x);
		if(!x) return 0;
		for(int i=1;x!=0;i++)
		{
			sol+=(x%10)*f[i];
			x/=10;
		}
		printf("%d\n",sol);
	}
	return 0;
}