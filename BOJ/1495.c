#include <stdio.h>

int check[100][1001]={0};
int v[100]={0};

int main()
{
    int i,j;
    int n,s,m;
    scanf("%d %d %d",&n,&s,&m);
    for(i=0;i<n;i++) scanf("%d",v+i);

    if(s+v[0]>=0&&s+v[0]<=m) check[0][s+v[0]]=1;
    if(s-v[0]>=0&&s-v[0]<=m) check[0][s-v[0]]=1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(check[i-1][j]!=0)
            {
                 if(j+v[i]>=0&&j+v[i]<=m) check[i][j+v[i]]=1;
                 if(j-v[i]>=0&&j-v[i]<=m) check[i][j-v[i]]=1;
            }
        }
    }
    int x=-1;
    for(i=0;i<=m;i++)
    {
        if(check[n-1][i]==1) x=i;
    }
    printf("%d",x);
    return 0;
}