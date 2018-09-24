#include <stdio.h>
int main()
{
 int a,b,c,d,p;
 int x,y;
 scanf("%d\n%d\n%d\n%d\n%d",&a,&b,&c,&d,&p);
 x=p*a;
 if(p>c) y=b+d*(p-c);
 else y=b;
 if(x<y) printf("%d",x);
 else printf("%d",y);
 return 0;
}