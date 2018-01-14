#include <stdio.h>
int main()
{
 int i,check=0;
 char a[101]={0};
 scanf("%s",a);
 for(i=0;a[i]!=0;i++)
  if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') check++;
 printf("%d",check);
 return 0;
}