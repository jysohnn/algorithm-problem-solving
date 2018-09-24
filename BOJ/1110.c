#include <stdio.h>
int main()
{
 int n,i;
 int a_c,b_c,a,b;
 scanf("%d",&n);
 a_c=n/10;
 b_c=n%10;
 a=a_c,b=b_c;
 for(i=1;1;i++)
 {
  int tmp=(a+b)%10;
  a=b,b=tmp;
  if(a==a_c&&b==b_c) break;
 }
 printf("%d\n",i);
 return 0;
}