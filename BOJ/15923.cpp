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
pll a[41];

int main()
{
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll x, y; scanf("%lld %lld", &x, &y);
        a[i].first = x; a[i].second = y;
    }
    for(ll i=0; i<n; i++)
    {
        ll j = (i+1) % n;
        sol += (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
    }
    cout<<sol;
    return 0;
}