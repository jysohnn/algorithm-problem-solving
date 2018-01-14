#include <stdio.h>
int main()
{	
	int n,i,j;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int a,b;
		int suma=0,sumb=0;
		for(j=0;j<9;j++)
		{
			scanf("%d %d",&a,&b);
			suma=suma+a;
			sumb=sumb+b;
		}
		if(suma>sumb) printf("Yonsei\n");
		else if(suma==sumb) printf("Draw\n");
		else printf("Korea\n");
	}
	return 0;
}