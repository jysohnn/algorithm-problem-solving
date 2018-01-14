#include <stdio.h>

int check[125]={0};
int max=0,u=0;

int main()
{
	char a;
	while((a=getchar())!= EOF)
	{
		if(a>=97) check[a-32]++;
		else check[a]++;
	}
	for(int i=0;i<125;i++)
		if(check[i]>max) {max=check[i]; a=i;}
	for(int i=0;i<125;i++)
		if(check[i]==max) u++;
	if(u>1) printf("?");
	else printf("%c",a);
	return 0;
}