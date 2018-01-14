#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,x=0,y=0;
	char* a=(char*)malloc(sizeof(char)*10001);
	for(i=0;i<10000;i++) a[i]=0;
	scanf("%s",a);
	for(i=2;a[i]!=0;i++)
	{
		if(a[i-2]=='J'&&a[i-1]=='O'&&a[i]=='I') x++;
		if(a[i-2]=='I'&&a[i-1]=='O'&&a[i]=='I') y++;
	}
	printf("%d\n%d\n",x,y);
	return 0;
}