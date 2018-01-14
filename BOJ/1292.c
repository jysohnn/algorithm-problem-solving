#include <stdio.h>
int main()
{
 int a[1000];
 int i,j,check=0;
 int x,y,sum=0;
 for(i=1;check!=1000;i++)
  for(j=1;j<=i;j++) {a[check]=i;check++;if(check==1000) break;}
 scanf("%d %d",&x,&y);
 for(i=x-1;i<=y-1;i++) sum=sum+a[i];
 printf("%d",sum);
 return 0;
}