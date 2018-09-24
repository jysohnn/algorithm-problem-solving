#include <stdio.h>
int main()
{
 int n,a,b;
 int i;
 scanf("%d %d %d",&n,&a,&b);
 for(i=0;i<n;i++)
 {
  int x;
  scanf("%d",&x);
  if(x*x<=a*a+b*b) printf("DA\n");
  else printf("NE\n");
 }
 return 0;
}