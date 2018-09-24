#include <stdio.h>
char s[5]={'D','C','B','A','E'};
int main()
{
    int i,j;
	for(i=0;i<3;i++)
	{
		int a[4];
		for(j=0;j<4;j++) scanf("%d",a+j);
		printf("%c\n",s[a[0]+a[1]+a[2]+a[3]]);
	}
    return 0;
}