#include <stdio.h>
int main()
{
 int a[3];
 while(1)
 {
  scanf("%d %d %d",a,a+1,a+2);
  if(a[0]+a[1]+a[2]==0) break;
  if(a[0]+a[1]<=a[2]||a[0]+a[2]<=a[1]||a[1]+a[2]<=a[0]) printf("Invalid\n");
  else{
  if(a[0]==a[1]&&a[1]==a[2]) printf("Equilateral\n");
  else if(a[0]==a[1]||a[1]==a[2]||a[0]==a[2]) printf("Isosceles\n");
  else printf("Scalene\n");}
 }
 return 0;
}