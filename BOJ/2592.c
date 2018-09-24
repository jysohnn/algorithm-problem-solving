#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int n=10;
	int sum=0;
	
	int* a=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++) scanf("%d",a+i);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int tmp=a[j];
			 	a[j]=a[j+1];
			 	a[j+1]=tmp;
			}	
		}
	}
	for(i=0;i<n;i++) sum=sum+a[i];
	
	int count=1;
	int count_max=1;
	int check=a[0];
	
	for(i=0;i<n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			count++;
			if(count>count_max)
			{
				count_max=count;
				check=a[i];
			}
		 }
		else count=1;
	}
	
	printf("%d\n%d\n",sum/n,check);
	
	free(a);
    return 0;
}