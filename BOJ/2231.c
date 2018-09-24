#include <stdio.h>
int main()
{
 int x,n,a[7];
 scanf("%d",&x);
 for(n=0;n<=x;n++)
 {
  a[0]=n%10,a[1]=(n/10)%10,a[2]=(n/100)%10,a[3]=(n/1000)%10,a[4]=(n/10000)%10,a[5]=(n/100000)%10,a[6]=(n/1000000)%10;
  int sum=n+a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6];
  if(sum==x) {printf("%d",n);return 0;}
 }
 printf("0");
 return 0;
}