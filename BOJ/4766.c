#include <stdio.h>
int main()
{
	int i;
	double x,tmp=0;
	for(i=0;1;i++)
	{
		scanf("%lf",&x);
		if(x==999) break;
		if(i)
		{
			printf("%.2lf\n",x-tmp);
		}
		tmp=x;
	}
	return 0;
}