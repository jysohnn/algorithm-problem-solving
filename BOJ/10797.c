#include <stdio.h>
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==n) count++;
	}
	printf("%d",count);
	return 0;
}