#include <cstdio>

long long cal(long long x)
{
    long long n;
    for(n=0;x>n*(n+1);n++);
    if(n*(n-1) < x && x <= n*n) return n*2-1;
    else return n*2;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        long long x,y,dis;
        scanf("%lld %lld",&x,&y);
        dis = y-x;
        printf("%lld\n",cal(dis));
    }
    return 0;
}