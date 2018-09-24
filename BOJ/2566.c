#include <stdio.h>

int main()
{
	int i;
	int max=0,check=0;
	
	for(i=0;i<81;i++)
	{
		int a;
		scanf("%d",&a);
		if(a>max)
		{
			max=a;
			check=i;
		}
	}
	printf("%d\n%d %d\n",max,check/9+1,check%9+1);
    return 0;
}