#include <stdio.h>
int main()
{
 int n,i,j;
 int a[50]={0},b[50]={0};
 int sum=0;

 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%d",a+i);
 for(i=0;i<n;i++) scanf("%d",b+i);

 for(i=n-1;i>0;i--)
 {
  for(j=0;j<i;j++)
  {
   if(a[j]>a[j+1])
   {
    int tmp;
    tmp=a[j+1];
    a[j+1]=a[j];
    a[j]=tmp;
   }
  }
 }

 for(i=n-1;i>0;i--)
 {
  for(j=0;j<i;j++)
  {
   if(b[j]>b[j+1])
   {
    int tmp;
    tmp=b[j+1];
    b[j+1]=b[j];
    b[j]=tmp;
   }
  }
 }

for(i=0;i<n;i++) sum=sum+a[i]*b[n-i-1];
printf("%d\n",sum);

return 0;
}
