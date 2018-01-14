#include <stdio.h>
int main()
{
 int n,i,sum=1;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int a;
  scanf("%d",&a);
  sum=sum+a-1;
 }
 printf("%d",sum);
 return 0;
}