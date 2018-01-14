#include <stdio.h>
int main()
{
 while(1)
 {
  int a,b;
  scanf("%d %d",&a,&b);
  if(a+b==0) break;
  if(a>b) printf("Yes\n");
  else printf("No\n");
 }
 return 0;
}