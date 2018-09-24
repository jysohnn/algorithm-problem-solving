#include <stdio.h>
int main()
{
 int t,i;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  int n,j;
  float sum=0,asum=0,a,b;
  scanf("%d",&n);
  for(j=0;j<n;j++)
  {
   scanf("%f %f",&a,&b);
   asum=asum+a;
   sum=sum+a*b;
  }
  printf("%d %.1f\n",(int)asum,sum/asum);
 }
 return 0;
}