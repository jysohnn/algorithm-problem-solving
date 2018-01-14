#include <stdio.h>
int main()
{
	int a[50];
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++) scanf("%d",a+i);
	for(i=t-1;i>0;i--)
	 for(j=0;j<i;j++)
	  if(a[j]>a[j+1])
	  {
	  	int tmp=a[j];
	  	a[j]=a[j+1];
	  	a[j+1]=tmp;
	  }
	  printf("%d",a[0]*a[t-1]);
	return 0;
}