#include <cstdio>

int a[15][15];

int main()
{
    for(int i=0;i<15;i++) a[0][i]=i;
    for(int i=0;i<15;i++) a[i][0]=0;
    for(int i=1;i<15;i++)
        for(int j=1;j<15;j++) a[i][j] = a[i][j-1] + a[i-1][j];

    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int k,n;
        scanf("%d %d",&k,&n);
        printf("%d\n",a[k][n]);
    }
    return 0;
}