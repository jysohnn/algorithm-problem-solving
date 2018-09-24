#include <stdio.h>
int main()
{
 int i,j,x=1,y=1;
 char a[8]={0};
 char b[8]={0};
 int a_max=0,a_min=0,b_max=0,b_min=0;
 scanf("%s %s",a,b);
 for(i=7;i>=0;i--)
 {
  if(a[i]!=0)
  {
   if(a[i]=='5'||a[i]=='6')
   {
    a_max+=6*x;
    a_min+=5*x;
    x=x*10;
   }
   else
   {
    a_max+=(int)(a[i]-48)*x;
    a_min+=(int)(a[i]-48)*x;
    x=x*10;
   }
  }
  if(b[i]!=0)
  {
   if(b[i]=='5'||b[i]=='6')
   {
    b_max+=6*y;
    b_min+=5*y;
    y=y*10;
   }
   else
   {
    b_max+=(int)(b[i]-48)*y;
    b_min+=(int)(b[i]-48)*y;
    y=y*10;
   }
  }
 }
 printf("%d %d\n",a_min+b_min,a_max+b_max);
 return 0;
}