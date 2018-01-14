#include <stdio.h>
int func(int a,int b)
{
 int i,x=a;
 for(i=1;i<b;i++) a=a*x;
 return a;
};
int main()
{
 int t,i;
 scanf("%d",&t);
 for(i=0;i<t;i++)
 {
  int a,b;
  scanf("%d %d",&a,&b);
  a=a%10;
  switch(a)
  {
   case 0: a=10; break;
   case 1: a=1; break;
   case 2:
   case 3: b=b%4; a=func(a,b+4);break;
   case 4: b=b%2; a=func(a,b+4);break;
   case 5: a=5; break;
   case 6: a=6; break;
   case 7:
   case 8: b=b%4;a=func(a,b+4);break;
   case 9: b=b%2;a=func(a,b+2);break;
  }
  if(a==10) printf("10\n");
  else printf("%d\n",a%10);
 }
 return 0;
}