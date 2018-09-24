#include <cstdio>

int a,b,v;

int main()
{
    scanf("%d %d %d",&a,&b,&v);
    v -= a;
    if(v <= 0) printf("1");
    else
    {
        if(v % (a-b)) v += (a-b);
        v /= (a-b);
        printf("%d",v+1);
    }
    return 0;
}