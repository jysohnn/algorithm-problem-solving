#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <tuple>

using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll>;

const ll N = 75001;
ll t, n;
tll p[N];
ll a[4*N + 1];
ll lazy[4*N + 1];

void update(ll n, ll nl, ll nr, ll l, ll r, ll v)
{
    if(lazy[n])
    {
        a[n] += (nr-nl+1) * lazy[n];
        if(nl!=nr) lazy[2*n] += lazy[n];
        if(nl!=nr) lazy[2*n+1] += lazy[n];
        lazy[n] = 0;
    }

    if(r < nl || nr < l) return;
    else if(l <= nl && nr <= r)
    {
        a[n] += (nr-nl+1) * v;
        if(nl!=nr) lazy[2*n] += v;
        if(nl!=nr) lazy[2*n+1] += v;
    }
    else
    {
        ll mid = (nl + nr) / 2;
        update(2*n, nl, mid, l, r, v);
        update(2*n+1, mid + 1, nr, l, r, v);
        a[n] = a[2*n] + a[2*n+1];
    }
}

ll query(ll n, ll nl, ll nr, ll l, ll r)
{
    if(lazy[n])
    {
        a[n] += (nr-nl+1) * lazy[n];
        if(nl!=nr) lazy[2*n] += lazy[n];
        if(nl!=nr) lazy[2*n+1] += lazy[n];
        lazy[n] = 0;
    }

    if(r < nl || nr < l) return 0;
    else if(l <= nl && nr <= r) return a[n];
    else
    {
        ll mid = (nl + nr) / 2;
        return query(2*n, nl, mid, l, r) + query(2*n+1, mid + 1, nr, l, r);
    }
}

bool cmp1(tll& x, tll& y)
{
    if(get<1>(x) < get<1>(y)) return true;
    else if(get<1>(x) > get<1>(y)) return false;
    else return get<0>(x) < get<0>(y);
}
bool cmp2(tll& x, tll& y)
{
    if(get<0>(x) > get<0>(y)) return true;
    else if(get<0>(x) < get<0>(y)) return false;
    else return get<1>(x) < get<1>(y);
}

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));

        ll idx = 0, sol = 0;
        scanf("%lld", &n);
        for(ll i=0; i<n; i++) scanf("%lld %lld", &get<0>(p[i]), &get<1>(p[i]));
        sort(p, p+n, cmp1);
        get<2>(p[0]) = idx;
        for(ll i=1; i<n; i++)
        {
            if(get<1>(p[i]) != get<1>(p[i-1])) get<2>(p[i]) = ++idx;
            else get<2>(p[i]) = idx;
        }
        sort(p, p+n, cmp2);
        for(ll i=0; i<n; i++)
        {
            sol += query(1, 0, idx, 0, get<2>(p[i]));
            update(1, 0, idx, get<2>(p[i]), get<2>(p[i]), 1);
        }
        printf("%lld\n", sol);
    }
    return 0;
}