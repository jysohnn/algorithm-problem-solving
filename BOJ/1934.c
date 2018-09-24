#include <stdio.h>
int main()
{
 int t,i,j;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  int a,b,min,a_t,b_t,l=1;
  scanf("%d %d",&a,&b);
  if(a>b) min=b;
  else min=a;
  a_t=a,b_t=b;
  for(j=2;j<=min;j++)
   if(a%j==0&&b%j==0) l=l*j,a=a/j,b=b/j,min=min/j,j--;
  printf("%d\n",a_t*b_t/l);
 }
 return 0;
}