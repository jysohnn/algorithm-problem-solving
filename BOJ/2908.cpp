#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int i,j;
	char a[100],b[100];
	scanf("%s %s",a,b);
	for(i=0;a[i]!=0;i++);
	for(j=0;b[j]!=0;j++);
	reverse(a,a+i);
	reverse(b,b+i);
	i=atoi(a), j=atoi(b);
	if(i>j) printf("%d",i);
	else printf("%d",j);
	return 0;
}