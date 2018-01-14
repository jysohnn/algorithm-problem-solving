#include <stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int x,sum=0;
		scanf("%d",&x);
		for(j=1;j<=x;j++) sum=sum+(j*j*j+3*j*j+2*j)/2;
		printf("%d\n",sum);
	}
	return 0;
}