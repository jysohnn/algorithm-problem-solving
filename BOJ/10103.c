#include <stdio.h>
int main()
{
 int n,i;
 int a=100,b=100;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  int x,y;
  scanf("%d %d",&x,&y);
  if(x>y) b=b-x;
  else if(x<y) a=a-y;
 }
 printf("%d\n%d",a,b);
 return 0;
}