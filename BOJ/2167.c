#include <stdio.h>
int main()
{
    int a[301][301];
    int i,j,n,m,t;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++) scanf("%d",&a[i][j]);
    scanf("%d",&t);
    while(t--)
    {
        int b,c,d,e,sum=0;
        scanf("%d %d %d %d",&b,&c,&d,&e);
        for(i=b-1;i<d;i++)
            for(j=c-1;j<e;j++) sum+=a[i][j];
        printf("%d\n",sum);
    }
    return 0;
}