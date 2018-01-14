#include <stdio.h>

int main()
{
	int i;
	int max=0,check=0;
	
	for(i=0;i<9;i++)
	{
		int a;
		scanf("%d",&a);
		if(a>max)
		{
			max=a;
			check=i+1;
		}
	}
	printf("%d\n%d\n",max,check);
    return 0;
}