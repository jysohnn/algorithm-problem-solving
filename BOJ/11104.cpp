#include <cstdio>

int t;
char a[25];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        long long sum = 0;
        scanf("%s",a);
        for(int i=0;i<24;i++) sum *= 2, sum += (a[i]-'0');
        printf("%lld\n",sum);
    }
    return 0;
}