#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	int n=5;
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
	
	printf("%d\n%d\n",sum/n,a[2]);
	
	free(a);
    return 0;
}