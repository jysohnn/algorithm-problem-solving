#include <stdio.h>
int main()
{
	int i,sum=0;
	int a[7]={0};
	int o=0,t=0;
	for(i=1;i<7;i++) scanf("%d",a+i);
	sum=sum+a[6]+a[5]+a[4];
	if(a[5]*11>=a[1]) a[1]=0;
	else a[1]=a[1]-a[5]*11;
	if(a[4]*5>=a[2])
	{
	 a[2]=0;
	 o=o+(a[4]*5-a[2])*4;	
	}
	else a[2]=a[2]-a[4]*5;
	sum=sum+(a[3]+3)/4;
	if(a[3]%4==3) {t++;o=o+5;}
	else if(a[3]%4==2){t=t+3;o=o+6;}
	else if(a[3]%4==1){t=t+5;o=o+7;}
	if(t>=a[2]) {a[2]=0;o=o+(t-a[2])*4;}
	else a[2]=a[2]-t;
	if(o>=a[1]) a[1]=0;
	else {a[1]=a[1]-o;o=0;}
	sum=sum+(a[2]+8)/9;
	if(a[2]%9!=0)
	{
		o=o+36-(a[2]%9)*4;
	}
	if(a[1]>o) sum=sum+(a[1]-o+35)/36;
	printf("%d\n",sum);
	return 0;
}