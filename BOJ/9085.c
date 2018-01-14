#include <stdio.h>
int main()
{
 int n,i,j;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int m,a,sum=0;
  scanf("%d",&m);
  for(j=0;j<m;j++)
  {
   scanf("%d",&a);
   sum=sum+a;
  }
  printf("%d\n",sum);
 }
 return 0;
}