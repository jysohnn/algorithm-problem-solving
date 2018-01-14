#include <stdio.h>
int main()
{
 int n,sum=0;
 int i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int a,b;
  scanf("%d %d",&a,&b);
  sum=sum+b%a;
 }
 printf("%d\n",sum);
 return 0;
}