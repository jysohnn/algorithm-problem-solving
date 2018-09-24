#include <cstdio>
int main()
{
	char a[100];
	int b,n = 0;
	scanf("%s %d",a,&b);
	for(int i=0;a[i]!=0;i++)
	{
		n *= b;
		if(a[i] > 64) a[i] -= 55;
		else a[i] -= '0';
		n += a[i];
	}
	printf("%d",n);
    return 0;
}