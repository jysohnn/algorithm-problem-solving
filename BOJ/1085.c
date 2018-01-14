#include <stdio.h>
int main()
{
 int x,y,w,h,i,j;
 int a[4];
 scanf("%d %d %d %d",&x,&y,&w,&h);
 a[0]=x,a[1]=y,a[2]=w-x,a[3]=h-y;
 for(i=3;i>0;i--)
  for(j=0;j<i;j++)
   {
    if(a[j]>a[j+1])
    {
     int t=a[j];
     a[j]=a[j+1];
     a[j+1]=t;
    }
   }
 printf("%d",a[0]);
 return 0;
}