#include <stdio.h>
#include <stdlib.h>

int main()
{
    char** a[11];
    int n=5,m=3,i,j,k,x;
    for(i=0;i<11;i++)
    {
        a[i]=(char**)malloc(sizeof(char*)*m);
        for(j=0;j<m;j++)
        {
            a[i][j]=(char*)malloc(sizeof(char)*n);
            for(k=0;k<n;k++) a[i][j][k]=' ';
        }
        n=n*2+1;
        m=m*2;
    }
    n=5,m=3;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++) a[0][i][j]=' ';
    for(i=0;i<n;i++) a[0][0][i]='*';
    a[0][1][1]='*';
    a[0][1][3]='*';
    a[0][2][2]='*';
    for(i=1;i<11;i++)
    {
        for(j=0;j<m;j++)
            for(k=0;k<n;k++)
            {
                a[i][j][k]=a[i-1][j][k];
                a[i][j][k+n+1]=a[i-1][j][k];
                a[i][j+m][k+(n+1)/2]=a[i-1][j][k];
            }
        n=n*2+1;
        m=m*2;
    }
    scanf("%d",&x);
    x=x/3,i=0;
    for(i=0;x!=1;i++) x=x/2;
    x=i,n=5,m=3;
    for(i=0;i<x;i++) n=n*2+1;
    for(i=0;i<x;i++) m=m*2;
    for(i=m-1;i>=0;i--)
    {
        for(j=0;j<n;j++) putchar(a[x][i][j]);
        putchar('\n');
    }
    return 0;
}