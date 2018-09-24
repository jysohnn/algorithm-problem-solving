#include <stdio.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		char a[21]={0},b[21]={0};
		scanf("%s %s",a,b);
		printf("Distances:");
		for(j=0;a[j]!=0;j++)
		{
			char x=b[j]-a[j];
			if(x>=0) printf(" %d",x);
			else printf(" %d",x+26);
		}
		printf("\n");
	}
	return 0;
}