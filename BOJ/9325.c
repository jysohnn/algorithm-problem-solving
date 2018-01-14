#include <stdio.h>
int main()
{
 int n;
 int i,j;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int a;
  int sum=0;
  scanf("%d",&sum);
  scanf("%d",&a);
  for(j=0;j<a;j++)
  {
   int b,c;
   scanf("%d %d",&b,&c);
   sum=sum+b*c;
  }
  printf("%d\n",sum);
 }
 return 0;
}