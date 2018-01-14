#include <stdio.h>
int main()
{
 int a,b,i;
 char c[3]={0};
 for(i=1;1;i++)
 {
  int check;
  scanf("%d %s %d",&a,c,&b);
  if(c[0]=='E') return 0;
  else
  {
   if(c[0]=='>'&&c[1]==0) check=(a>b);
   else if(c[0]=='>'&&c[1]=='=') check=(a>=b);
   else if(c[0]=='<'&&c[1]==0) check=(a<b);
   else if(c[0]=='<'&&c[1]=='=') check=(a<=b);
   else if(c[0]=='=') check=(a==b);
   else check=(a!=b);
  }
  if(check) printf("Case %d: true\n",i);
  else printf("Case %d: false\n",i);
 }
}