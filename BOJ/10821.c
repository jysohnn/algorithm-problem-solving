#include <stdio.h>
int main()
{
 int i,check=1;
 char a[101]={0};
 scanf("%s",a);
 for(i=0;a[i]!=0;i++)
 {
  if(!(a[i]>=48&&a[i]<=57)&&a[i]!=',') check--;
  if(a[i]==',') check++;
 }
 printf("%d",check);
 return 0;
}