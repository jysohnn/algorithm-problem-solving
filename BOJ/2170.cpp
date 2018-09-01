#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, sol = 0;
pll a[1000001];
ll l, r;

int main()
{
    scanf("%lld", &n);
    for(ll i=0; i<n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
    sort(a, a+n);
    l = a[0].first, r = a[0].second;
    for(ll i=1; i<n; i++)
    {
        ll cl = a[i].first, cr = a[i].second;
        if(cl <= r) r = max(r, cr);
        else sol += (r-l), l = cl, r = cr;
    }
    sol += (r-l);
    printf("%lld", sol);
    return 0;
}