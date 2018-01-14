#include <stdio.h>
int main()
{
 int x[3],y[3];
 int a=0,b=0,check1=0,check2=0,i;
 scanf("%d %d\n%d %d\n%d %d",x,y,x+1,y+1,x+2,y+2);
 for(i=0;i<3;i++)
 {
  if(x[i]>a) a=x[i];
  if(y[i]>b) b=y[i];
 }
 for(i=0;i<3;i++)
 {
  if(x[i]==a) check1++;
  if(y[i]==b) check2++;
 }
 if(check1==2)
  for(i=0;i<3;i++)
   {
    if(a!=x[i]){a=x[i];break;}
   }
 if(check2==2)
  for(i=0;i<3;i++)
   {
    if(b!=y[i]){b=y[i];break;}
   }
 printf("%d %d\n",a,b);
 return 0;
}