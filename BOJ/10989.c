#include <stdio.h>
int main()
{
	int a[10001]={0};
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for(i=1;i<=10000;i++) 
        if(a[i]!=0) 
		{
			printf("%d\n",i);
			a[i]--;
			i--;
		}
	return 0;
}