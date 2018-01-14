#include <stdio.h>
int main()
{
	int i;
	int sum=0,max=0;
	for(i=0;i<4;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		sum=sum-a+b;
		if(sum>max) max=sum;
	}
	printf("%d\n",max);
    return 0;
}