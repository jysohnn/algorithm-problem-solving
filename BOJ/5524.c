#include <stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char a[100]={0};
		scanf("%s",a);
		for(j=0;a[j]!=0;j++)
			if(a[j]<=90) a[j]=a[j]+32;
		printf("%s\n",a);
	}
	return 0;
}