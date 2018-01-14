#include <cstdio>

int n,k;
int c[101];
int d[10001] = {1};

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",c+i);
    for(int i=0;i<n;i++)
        for(int j=1;j<=k;j++)
            if(j-c[i] >= 0) d[j] += d[j-c[i]];
    printf("%d",d[k]);
    return 0;
}