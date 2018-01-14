#include <cstdio>

int n;
long long t[36] = {1};

int main()
{
    scanf("%d",&n);
    for(int i=1;i<36;i++)
        for(int j=0;j<i;j++) t[i] += t[j] * t[i-j-1];
    printf("%lld",t[n]);
    return 0;
}