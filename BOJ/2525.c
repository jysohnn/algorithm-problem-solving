#include <stdio.h>
int main()
{
 int h,m,x;
 scanf("%d %d %d",&h,&m,&x);
 h=h+x/60;
 x=x%60;
 h=h%24;
 m=m+x;
 h=h+m/60;
 m=m%60;
 h=h%24;
 printf("%d %d\n",h,m);
 return 0;
}