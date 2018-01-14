#include <stdio.h>
#include <stdlib.h>
int main()
{
 int n,i,x,count=0;
 scanf("%d",&n);
 int* a=(int*)malloc(4*n);
 for(i=0;i<n;i++) scanf("%d",a+i);
 scanf("%d",&x);
 for(i=0;i<n;i++)
 {
  if(a[i]==x) count++;
 }
 printf("%d",count);
 return 0;
}