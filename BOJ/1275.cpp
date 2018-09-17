#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, q;
ll a[100005] = {0};

void update(ll x, ll v)
{
    for(ll i=x; i <= n; i += (i & -i))
        a[i] += v;
}
ll query(ll x)
{
    ll ret = 0;
    for(ll i=x; i >= 1; i -= (i & -i))
        ret += a[i];
    return ret;
}
ll sol(ll x, ll y)
{
    if(x > y) swap(x, y);
    return query(y) - query(x-1);
}

int main()
{
    scanf("%lld %lld", &n, &q);
    for(ll i=1; i <= n; i++)
    {
        ll v; scanf("%lld", &v);
        update(i, v);
    }
    for(ll i=0; i < q; i++)
    {
        ll x, y, xx, v;
        scanf("%lld %lld %lld %lld", &x, &y, &xx, &v);
        printf("%lld\n", sol(x, y));
        update(xx, v-sol(xx, xx));
    }
    return 0;
}