#include <cstdio>

int n, s;
int a[21];
int sum = 0;
int sol = 0;

void check(int x)
{
    if(x == n)
    {
        if(sum == s) sol++;
        return;
    }
    check(x+1);
    sum += a[x];
    check(x+1);
    sum -= a[x];
}

int main()
{
    scanf("%d %d",&n, &s);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    check(0);
    if(s == 0) printf("%d",sol-1);
    else printf("%d",sol);
    return 0;
}