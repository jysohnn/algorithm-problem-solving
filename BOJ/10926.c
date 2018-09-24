#include <stdio.h>
int main()
{
 int i;
 char a[101]={0};
 scanf("%s",a);
 for(i=0;a[i]!=0;i++){}
 a[i]='?',a[i+1]='?',a[i+2]='!';
 printf("%s",a);
 return 0;
}