#include <stdio.h>
int f(int x,int y)
{
	return x+y;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",f(a,b));
	return 0;
}