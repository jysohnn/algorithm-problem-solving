#include <stdio.h>
int main()
{
	char a[3]={0};
	float sum=0.0;
	scanf("%s",a);
	switch(a[0])
	{
		case 'A':sum=sum+4.0;break;
		case 'B':sum=sum+3.0;break;
		case 'C':sum=sum+2.0;break;
		case 'D':sum=sum+1.0;break;
		default : break;
	}
	switch(a[1])
	{
		case '+':sum=sum+0.3;break;
		case '0':break;
		case '-':sum=sum-0.3;break;
		default : break;
	}
	printf("%.1f",sum);
	return 0;
}