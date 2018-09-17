#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, k;
ll a[300001];

int main()
{
    ll sol = 0, c = 0;
    scanf("%lld %lld", &n, &k);
    for(ll i=0; i<n; i++) scanf("%lld", a+i);
    sort(a, a+n);
    for(ll i=0; i<n; i++)
    {
        sol += c * a[i];
        if(c < k) c++; 
    }
    printf("%lld", sol);
    return 0;
}