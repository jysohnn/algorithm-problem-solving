#include <stdio.h>
int main()
{
 int sum=0;
 int i;
 for(i=0;i<5;i++)
 {
  int a;
  scanf("%d",&a);
  sum=sum+a;
 }
 printf("%d",sum);
 return 0;
}