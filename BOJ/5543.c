#include <stdio.h>
int main()
{
 int i,j;
 int a[3],b[2];
 scanf("%d\n%d\n%d\n%d\n%d",a,a+1,a+2,b,b+1);
 for(i=2;i>0;i--)
  for(j=0;j<i;j++)
   {
    if(a[j]>a[j+1])
    {
     int t=a[j];
     a[j]=a[j+1];
     a[j+1]=t;
    }
   }
 if(b[0]>b[1]) printf("%d",a[0]+b[1]-50);
 else printf("%d",a[0]+b[0]-50);
 return 0;
}