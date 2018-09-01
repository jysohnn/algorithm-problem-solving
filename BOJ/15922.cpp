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
pll a[100001];

int main()
{
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll x, y; scanf("%lld %lld", &x, &y);
        a[i].first = x;
        a[i].second = y;
    }
    sort(a, a+n);
    ll x = a[0].first;
    ll y = a[0].second;
    for(ll i=1; i<n; i++)
    {
        if(y < a[i].first)
        {
            sol += (y - x);
            x = a[i].first;
            y = a[i].second;
        }
        else if(y < a[i].second) y = a[i].second;
    }
    sol += (y - x);
    cout<<sol;
    return 0;
}