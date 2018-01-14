#include <stdio.h>
int main()
{
 char a[101]={0},b[101]={0};
 int i,n,check=0;
 scanf("%s",a);
 for(n=0;a[n]!=0;n++){}
 for(i=0;i<n;i++) b[i]=a[n-i-1];
 for(i=0;i<n;i++)
  if(a[i]!=b[i]) check++;
 if(check==0) printf("1");
 else printf("0");
 return 0;
}