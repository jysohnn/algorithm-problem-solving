#include <cstdio>

int t;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int n,m,sol=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<n;j++)
				if((i*i+j*j+m) % (i*j) == 0) sol++;
		printf("%d\n",sol);
	}
	return 0;
}