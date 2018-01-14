#include <stdio.h>
int main()
{
 int i,j;
 char a[11]={0};
 scanf("%s",a);
 for(i=10;i>0;i--)
  for(j=0;j<i;j++)
   {
    if(a[j]<a[j+1])
    {
     int tmp=a[j];
     a[j]=a[j+1];
     a[j+1]=tmp;
    }
   }
 for(i=0;a[i]!=0;i++) printf("%c",a[i]);
 return 0;
}