#include <stdio.h>
int main()
{
 int i,a,b,x[5];
 scanf("%d %d",&a,&b);
 for(i=0;i<5;i++)
 {
  scanf("%d",x+i);
  x[i]=x[i]-a*b;
 }
 printf("%d %d %d %d %d",x[0],x[1],x[2],x[3],x[4]);
 return 0;
}