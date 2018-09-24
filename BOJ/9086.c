#include <stdio.h>
int main()
{
 int n,i,j;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  char a[1001]={0};
  char x,y;
  scanf("%s",a);
  x=a[0];y=a[0];
  for(j=1;a[j]!=0;j++) y=a[j];
  printf("%c%c\n",x,y);
 }
 return 0;
}