#include <stdio.h>
int main()
{
	int i;
	int sum=0;
    for(i=0;i<5;i++)
    {
    	int n;
    	scanf("%d",&n);
    	if(n<=40) sum=sum+40;
    	else sum=sum+n;
	}
	printf("%d\n",sum/5);
    return 0;
}