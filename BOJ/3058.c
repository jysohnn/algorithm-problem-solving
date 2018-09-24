#include <stdio.h>

int main()
{
	int n;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int sum=0, min=100;
		for(j=0;j<7;j++)
		{
			int a;
			scanf("%d",&a);
			if(a%2==0)
			{
				sum=sum+a;
				if(a<min) min=a;
			}
		}
		printf("%d %d\n",sum,min);
	}
    return 0;
}