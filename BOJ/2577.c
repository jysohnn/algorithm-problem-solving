#include <stdio.h>
int main()
{
	int check[10]={0};
	int a,b,c,x;
	scanf("%d %d %d",&a,&b,&c);
	x=a*b*c;
	while(x!=0)
	{
		int tmp=x%10;
		check[tmp]++;
		x=x/10;
	}
	for(x=0;x<10;x++) printf("%d\n",check[x]);
	return 0;
}