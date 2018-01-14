#include <stdio.h>
int main()
{
	int i,sum=0;
	int a[4]={0};
	for(i=0;i<4;i++) {scanf("%d",a+i); sum=sum+a[i];}
	printf("%d\n%d\n",sum/60,sum%60);
	return 0;
}