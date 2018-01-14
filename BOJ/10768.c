#include <stdio.h>
int main()
{
 int m,n;
 scanf("%d\n%d",&m,&n);
 if(m>2) printf("After");
 else if(m==2)
 {
  if(n>18) printf("After");
  else if(n==18) printf("Special");
  else printf("Before");
 }
 else printf("Before");
 return 0;
}