#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<45827;i++)
    {
        if(n<i*i)
        {
            printf("%lld",i-1);
            break;
        }
    }
    return 0;
}