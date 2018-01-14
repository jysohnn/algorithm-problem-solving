#include <stdio.h>
int main()
{
	int a[3];
	int i,j;
	int n=3;
	for(i=0;i<3;i++) scanf("%d",a+i);
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
	for(i=0;i<n;i++) 
	{
		printf("%d",a[i]);
		if(i!=n-1) printf(" ");
	}
	printf("\n");
    return 0;
}