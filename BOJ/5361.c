#include <stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		double a[5];
		scanf("%lf %lf %lf %lf %lf",a,a+1,a+2,a+3,a+4);
		printf("$%.2lf\n",a[0]*350.34+a[1]*230.90+a[2]*190.55+a[3]*125.30+a[4]*180.90);
	}
	return 0;
}