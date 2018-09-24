#include <cstdio>
int main(){char a[101];scanf("%s",a);for(int i=0;a[i]!=0;i++){if(a[i]>96) a[i]-=32;else a[i]+=32;}printf("%s",a);}