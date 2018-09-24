#include <stdio.h>
int main()
{
 char a[100]={0};
 int i,check=0;
 while(1)
 {
  char c;
  c=getchar();
  if(c=='\n') break;
  if(c>=65&&c<=90){a[check]=c;check++;}
 }
 printf("%s",a);
 return 0;
}