#include <stdio.h>
int main()
{
	int i,a=0,b=0;
	for(i=0;i<4;i++)
	{
	  int x;
	  scanf("%d",&x);
	  a=a+x;
	}
	for(i=0;i<4;i++)
	{
	  int x;
	  scanf("%d",&x);
	  b=b+x;
	}
	if(a>b) printf("%d\n",a);
	else printf("%d\n",b);
	return 0;
}