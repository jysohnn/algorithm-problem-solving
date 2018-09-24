#include <stdio.h>
int main()
{
	int arr[1000]={0};
	int n,i,check=0;
	for(i=1;i<=99;i++) arr[i]=1;
	for(i=100;i<1000;i++)
	{
		int a,b,c;
		a=i%10;
		b=(i/10)%10;
		c=i/100;
		if((a-b)==(b-c)) arr[i]=1; 
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++) if(arr[i]==1) check++;
	printf("%d",check);
	return 0;
}