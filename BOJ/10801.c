#include <stdio.h>
int main()
{
 int i,a=0,b=0;
 int x[10],y[10];
 for(i=0;i<10;i++)
 {
  scanf("%d",x+i);
 }
 for(i=0;i<10;i++)
 {
  scanf("%d",y+i);
 }
 for(i=0;i<10;i++)
  if(x[i]>y[i]) a++;
  else if(x[i]<y[i]) b++;
 if(a>b) printf("A");
 else if(a<b) printf("B");
 else printf("D");
 return 0;
}