#include <stdio.h>
int main()
{
 int a[10],b[10];
 int i,j;
 for(i=0;i<10;i++) scanf("%d",a+i);
 for(i=0;i<10;i++) scanf("%d",b+i);
 for(i=9;i>0;i--)
  for(j=0;j<i;j++)
   {
    if(a[j]>a[j+1])
    {
     int t=a[j];
     a[j]=a[j+1];
     a[j+1]=t;
    }
   }
 for(i=9;i>0;i--)
   for(j=0;j<i;j++)
    {
     if(b[j]>b[j+1])
     {
      int t=b[j];
     b[j]=b[j+1];
      b[j+1]=t;
     }
    }
 printf("%d %d",a[9]+a[8]+a[7],b[9]+b[8]+b[7]);
 return 0;
}