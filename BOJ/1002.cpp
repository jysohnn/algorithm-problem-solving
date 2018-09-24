#include <cstdio>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x1,y1,r1,x2,y2,r2,sol,a1,a2,b;
        scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&r1,&x2,&y2,&r2);
        a1 = (r1+r2)*(r1+r2), a2 = (r1-r2)*(r1-r2), b = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if(b == 0)
        {
            if(r1 == r2) sol = -1;
            else sol = 0;
        }   
        else if(b > r1*r1 && b > r2*r2)
        {
            if(a1 > b) sol = 2;
            else if(a1 == b) sol = 1;
            else sol = 0; 
        }   
        else
        {
            if(a2 < b) sol = 2;
            else if(a2 == b) sol = 1;
            else sol = 0; 
        }   
        printf("%lld\n",sol);
    }   
    return 0;
}