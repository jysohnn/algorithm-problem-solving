#include <cstdio>

int n, m, sol = 64;
char a[51][51];

void check(int x, int y)
{   
    int b = 0;
    int count = 0;
    for(int i=x;i>x-8;i--)
    {
        for(int j=y;j>y-8;j--)
        {   
            if(b % 2 == 0 && a[i][j] != 'W') count++;
            else if(b % 2 == 1 && a[i][j] != 'B') count++;
            b++;
        }
        b++;
    }
    if(count < sol) sol = count;
    count = 0, b = 0;
    for(int i=x;i>x-8;i--)
    {
        for(int j=y;j>y-8;j--)
        {
            if(b % 2 == 1 && a[i][j] != 'W') count++;
            else if(b % 2 == 0 && a[i][j] != 'B') count++;
            b++;
        }
        b++;
    }
    if(count < sol) sol = count;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",a[i]);
    for(int i=n-1;i>=7;i--)
        for(int j=m-1;j>=7;j--) check(i,j);
    printf("%d",sol);
    return 0;
}