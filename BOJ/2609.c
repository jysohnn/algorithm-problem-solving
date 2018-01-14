#include <stdio.h>
int main()
{
 int a,b,i,l=1,big,a_t,b_t;
 scanf("%d %d",&a,&b);
 a_t=a;
 b_t=b;
 if(a>b) big=a;
 else big=b;
 for(i=2;i<=big;i++)
  if(a%i==0&&b%i==0)
  {
   l=l*i;
   a=a/i;
   b=b/i;
   big=big/i;
   i--;
  }
 printf("%d\n%d\n",l,a_t*b_t/l);
 return 0;
}