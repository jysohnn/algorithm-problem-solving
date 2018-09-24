#include <stdio.h>
int main()
{
	int sum,i;
	int a[9];
	scanf("%d",&sum);
	for(i=0;i<9;i++) 
	{
		scanf("%d",a+i);
		sum=sum-a[i];
	}
	printf("%d",sum);
	return 0;
}