#include <stdio.h>
int main(i,x){int n;scanf("%d",&n);for(i=64,x=0;i!=0;i/=2){x+=n/i;n=n%i;}printf("%d",x);}