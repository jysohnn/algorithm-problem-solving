#include <stdio.h>
int main()
{
	int g,i,j=0,check=0;
	int x[100]={0};
	int y[100]={0};
	scanf("%d",&g);
	for(i=1;i*i<g;i++)
	{
		if(g%i==0) {x[j]=i;y[j]=g/i;j++;}
	}
	for(i=j-1;i>=0;i--)
	{
		if((y[i]-x[i])%2==0) 
		{
			printf("%d\n",x[i]+(y[i]-x[i])/2);
			check++;
		}
	}
	if(check==0) printf("-1\n");
	return 0;
}