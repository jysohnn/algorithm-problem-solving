#include <stdio.h>
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==1) count++;
	}
	
	if(count>n-count) printf("Junhee is cute!");
	else printf("Junhee is not cute!");
	return 0;
}