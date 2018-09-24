#include <stdio.h>
#include <stdlib.h>
int main()
{
 int n,i;
 scanf("%d",&n);
 int* a=(int*)malloc(sizeof(int)*n);
 int* b=(int*)malloc(sizeof(int)*n);
 for(i=0;i<n;i++) scanf("%d,%d",a+i,b+i);
 for(i=0;i<n;i++) printf("%d\n",a[i]+b[i]);
 return 0;
}