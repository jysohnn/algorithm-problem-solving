#include <cstdio>

int t;

int numZero(int n)
{
    int ret = 0;
    if(n == 0) return 1;
    while(n)
    {
        if(n%10 == 0) ret++;
        n /= 10;
    }
    return ret;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int a, b, sol = 0;
        scanf("%d %d",&a,&b);
        for(int i=a;i<=b;i++) sol += numZero(i);
        printf("%d\n",sol);
    }
    return 0;
}