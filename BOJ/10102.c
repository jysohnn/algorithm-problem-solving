#include <stdio.h>
int main()
{
 char c[16]={0};
 int a=0,b=0,n,i;
 scanf("%d\n%s",&n,c);
 for(i=0;i<n;i++)
 {
  if(c[i]=='A') a++;
  else if(c[i]=='B') b++;
 }
 if(a>b) printf("A");
 else if(a==b) printf("Tie");
 else printf("B");
 return 0;
}