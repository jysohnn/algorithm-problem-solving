#include <stdio.h>
int min(int a,int b)
{
 if(a>b) return b;
 else return a;
};
int main()
{
 int x;
 int a[1000][3]={0};
 int b[1000][3]={0};
 int n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
 for(i=0;i<n;i++)
 {
  if(i==0) b[i][0]=a[i][0],b[i][1]=a[i][1],b[i][2]=a[i][2];
  else b[i][0]=a[i][0]+min(b[i-1][1],b[i-1][2]),b[i][1]=a[i][1]+min(b[i-1][0],b[i-1][2]),b[i][2]=a[i][2]+min(b[i-1][0],b[i-1][1]);
 }
 x=min(b[n-1][0],b[n-1][1]);
 x=min(x,b[n-1][2]);
 printf("%d",x);
 return 0;
}