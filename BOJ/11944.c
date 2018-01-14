#include <stdio.h>
int main()
{
	char a[5]={0};
	int i,n,m,j;
	scanf("%s %d",a,&m);
	n=atoi(a);
	for(i=0;a[i]!=0;i++);
	if(i*n>=m)
	 for(j=0;j<m;j++) printf("%c",a[j%i]);
	else
	 for(j=0;j<n;j++) printf("%d",n);
	return 0;
}