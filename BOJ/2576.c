#include <stdio.h>
int main()
{
	int i;
	int sum=0,min=100;
	for(i=0;i<7;i++)
	{
		int n;
		scanf("%d",&n);
		if(n%2==1) 
		{
			sum=sum+n;
			if(n<min) min=n;
	    }
	}
	if(sum==0){printf("-1\n"); return 0;}
	printf("%d\n%d\n",sum,min);
    return 0;
}