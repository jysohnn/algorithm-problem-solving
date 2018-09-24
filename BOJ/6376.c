#include <stdio.h>

double facto(double n)
{
 if(n==0) return 1.0;
 else{
 int i;
 double mul=1.0;
 for(i=1;i<=n;i++) mul=mul*i;
 return mul;}
};

int main()
{
 int i,j;
 printf("n e\n");
 printf("- -----------\n");
 for(i=0;i<=9;i++)
 {
  double e=0.0;
  for(j=0;j<=i;j++) e=e+1/facto(j);
  if(i==0) printf("%d %d\n",i,(int)e);
  else if(i==1) printf("%d %d\n",i,(int)e);
  else if(i==2) printf("%d %.1lf\n",i,e);
  else printf("%d %.9lf\n",i,e);
  }
 return 0;
}