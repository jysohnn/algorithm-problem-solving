#include <stdio.h>
#include <stdlib.h>
int main()
{
 long long i,j,k=0;
 long long check=0;
 long long min,max;
 long long* n=(long long*)malloc(sizeof(long long)*1000001);
 for(i=0;i<1000001;i++) n[i]=0;
 n[0]=1,n[1]=1,n[2]=0;
 long long* p=(long long*)malloc(sizeof(long long)*1000001);
 for(i=0;i<1000001;i++) p[i]=0;
 long long* a=(long long*)malloc(sizeof(long long)*1000001);
 for(i=0;i<1000001;i++) a[i]=0;

 for(i=2;i<1000001;i++)
 {
  if(n[i]==0)
   for(j=2;i*j<1000001;j++) n[i*j]=1;
 }
 for(i=2;i<1000001;i++)
  if(n[i]==0) {p[k]=i;k++;}
 for(i=0;1;i++)
  if(p[i]==0) {check=i-1;break;}

 scanf("%lld %lld",&min,&max);
 long long x=max-min+1;

  for(i=0;i<=check;i++)
  {

    if(p[i]*p[i]>max) break;

    if(min%(p[i]*p[i])==0)
    {
     j=min/(p[i]*p[i]);
     for(;p[i]*p[i]*j<=max;j++) a[p[i]*p[i]*j-min]=1;
    }
    else
    {
     j=(min/(p[i]*p[i]))+1;
     for(;p[i]*p[i]*j<=max;j++) a[p[i]*p[i]*j-min]=1;
    }
  }

 for(i=0;min+i<=max;i++)
  if(a[i]==1) x--;
 printf("%lld\n",x);

 return 0;
}