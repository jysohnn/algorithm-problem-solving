#include <stdio.h>
int main()
{
 int n,i,j;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  char a[62]={0};
  scanf("%s",a);
  for(j=0;a[j]!=0;j++){}
  j--;
  if((a[j]-48)%2==0) printf("even\n");
  else printf("odd\n");
 }
 return 0;
}