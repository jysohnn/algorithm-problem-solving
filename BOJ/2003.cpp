#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m;
ll a[10002] = {0};
ll l, r, s;

int main()
{
    ll sol = 0;
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<n; i++) scanf("%lld", a+i);
    l = r = 0; s = a[l];

    while(l < n)
    {
        if(s >= m || r == n-1)
        {
            if(s == m) sol++;
            s -= a[l++];
        }
        else s += a[++r];
    }
    printf("%lld", sol);
    return 0;
}