#include <stdio.h>
void Phanoi(int x,int y,int n)
{
 if(n==1)
 {
  printf("%d %d\n",x,y);
 }
 else
 {
  Phanoi(x,6-x-y,n-1);
  printf("%d %d\n",x,y);
  Phanoi(6-x-y,y,n-1);
 }
};
int CountHanoi(int x,int y,int n)
{
 int sum=0;
 if(n==1) return 1;
 else
 {
  sum+=CountHanoi(x,6-x-y,n-1);
  sum++;
  sum+=CountHanoi(6-x-y,y,n-1);
 }
 return sum;
};
int main()
{
 int n;
 scanf("%d",&n);
 printf("%d\n",CountHanoi(1,3,n));
 Phanoi(1,3,n);
 return 0;
}