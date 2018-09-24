#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll a[7];
ll sol = 0;
ll one = 0, two = 0;

int main()
{
    for(ll i=1; i<7; i++) scanf("%lld", a+i);
    sol += a[6] + a[5] + a[4];
    one += a[5] * 11; two = a[4] * 5;

    sol += a[3] / 4;
    a[3] %= 4;
    if(a[3])
    {
        sol++;
        if(a[3] == 1) two += 5, one += 7;
        if(a[3] == 2) two += 3, one += 6;
        if(a[3] == 3) two += 1, one += 5;
    }
    if(two >= a[2]) two -= a[2], one += two * 4, a[2] = 0;
    else a[2] -= two, two = 0;
    sol += a[2] / 9;
    a[2] %= 9;
    if(a[2]) sol++, one += (9 - a[2]) * 4;

    if(one >= a[1]) one -= a[1], a[1] = 0;
    else a[1] -= one, one = 0;
    sol += a[1] / 36;
    a[1] %= 36;
    if(a[1]) sol++;
    
    printf("%lld", sol);
    return 0;
}