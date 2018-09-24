#include <stdio.h>
int main()
{
 int n,i,a[100]={0},x=0;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int check;
  scanf("%d",&check);
  a[check-1]++;
 }
 for(i=0;i<100;i++)
 {
  if(a[i]>=2) x=x+a[i]-1;
 }
 printf("%d",x);
 return 0;
}