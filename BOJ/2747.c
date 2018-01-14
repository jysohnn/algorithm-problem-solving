#include <stdio.h>

int fibo(int x)
{
	int i;
 	int a[46]={0,1};
 	for(i=2;i<46;i++)
 	{
 	 a[i]=a[i-1]+a[i-2];
	}
	return a[x];
};

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fibo(n));
	return 0;
}