#include <stdio.h>
int main()
{
 int a[6];
 int i,min=101,check=0,check2=0,sum=0;
 for(i=0;i<6;i++)
 {
  scanf("%d",a+i);
  sum=sum+a[i];
 }
 for(i=0;i<4;i++)
  if(min>a[i]){
   min=a[i];
   check=i;
   }
 if(a[4]>a[5]) check2=5;
 else check2=4;
 sum=sum-a[check]-a[check2];
 printf("%d",sum);
 return 0;
}