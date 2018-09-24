#include <stdio.h>
int main()
{
 int a[3],c[3];
 char b[4];
 int i,j;
 scanf("%d %d %d",a,a+1,a+2);
 scanf("%s",b);
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
 for(i=0;i<3;i++)
 {
  c[i]=a[b[i]-65];
 }
 printf("%d %d %d",c[0],c[1],c[2]);
 return 0;
}