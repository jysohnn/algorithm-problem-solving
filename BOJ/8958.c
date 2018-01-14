#include <stdio.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int sum=0,stack=1;
		char arr[81]={0};
		scanf("%s",arr);
		for(j=0;arr[j]!=0;j++)
		{
			if(arr[j]=='O')
			{
				sum+=stack;
				stack++;
			}
			else stack=1;
		}
		printf("%d\n",sum);
	}
	return 0;
}