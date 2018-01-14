#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int money;
		scanf("%d",&money);
		printf("%d ",money/25);
		money=money%25;
		printf("%d ",money/10);
		money=money%10;
		printf("%d ",money/5);
		money=money%5;
		printf("%d\n",money);
	}
    return 0;
}