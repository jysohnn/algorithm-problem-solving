#include <stdio.h>
int main()
{
	int n,i,check;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1/1\n");
		return 0;
	}
	for(i=1;1;i++)
	{
		if(n<=(i*i+i)/2)
		{
			check=i-1;
			break;
		}
	}
	n=n-(check*check+check)/2;
	if(i%2==0) printf("%d/%d\n",n,i-n+1);
	else printf("%d/%d\n",i-n+1,n);
	return 0;
}