#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    while(1)
    {
        int sol = INT_MAX;
        int a, c;
        scanf("%d %d",&a, &c);
        if(a == 0 && c == 0) break;
        sol = min(sol, 2*c - a);
        sol = min(sol, 2*a - c);
        if((a+c)%2 == 0) sol = min(sol, (a+c)/2);
        printf("%d\n",sol);
    }
    return 0;
}