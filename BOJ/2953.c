#include <stdio.h>
int main()
{
	int i,check=0,max=0;
	for(i=0;i<5;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(max<(a+b+c+d))
		{
			max=a+b+c+d;
			check=i+1;
		}
	}
	printf("%d %d",check,max);
	return 0;
}