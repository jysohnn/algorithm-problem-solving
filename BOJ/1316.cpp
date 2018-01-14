#include <stdio.h>
int main()
{
	int n,sol=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char a[101];
		bool check[126]={0};
		scanf("%s",a);
		check[a[0]]=true;
		for(int j=1;a[j]!=0;j++)
		{
			if(check[a[j]]==false || a[j]==a[j-1]) check[a[j]]=true;
			else {sol--; break;}
		}
		sol++;
	}
	printf("%d",sol);
	return 0;
}