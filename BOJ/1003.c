#include <stdio.h>
int main()
{
 int t,i,j;
 int a[41]={1,0};
 int b[41]={0,1};
 for(i=2;i<41;i++)
 {
  a[i]=a[i-1]+a[i-2];
  b[i]=b[i-1]+b[i-2];
 }
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  int n;
  scanf("%d",&n);
  printf("%d %d\n",a[n],b[n]);
 }
 return 0;
}