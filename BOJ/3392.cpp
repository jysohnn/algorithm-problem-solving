#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <tuple>

using namespace std;
using ll = long long;
using tll = tuple<ll, ll, ll, bool>;

const ll N = 30002;
ll n;
tll p[20002];
ll a[8*N + 1] = {0};
ll dp[8*N + 1] = {0};

void update(ll n, ll nl, ll nr, ll l, ll r, ll v)
{
    if(r < nl || nr < l) return;
    else if(l <= nl && nr <= r) a[n] += v; // query 범위안에 현재 node의 범위가 포함될 때
    else
    {
        ll mid = (nl + nr) / 2;
        update(2*n, nl, mid, l, r, v);
        update(2*n+1, mid + 1, nr, l, r, v);
    }

    if(a[n]) dp[n] = nr - nl + 1;
    else dp[n] = dp[2*n] + dp[2*n+1];
}

int main()
{
    ll idx = 0, sol = 0;
    scanf("%lld", &n);
    for(ll i=0; i<n; i++)
    {
        ll x, y, z, l;
        scanf("%lld %lld %lld %lld", &x, &y, &z, &l);
        p[idx++] = {x, y, l, 0}; // start
        p[idx++] = {z, y, l, 1}; // end
    }
    sort(p, p+idx);
    update(1, 0, N, get<1>(p[0]), get<2>(p[0])-1, 1);
    for(ll i=1; i<idx; i++)
    {
        ll d = get<0>(p[i]) - get<0>(p[i-1]);
        sol += d * dp[1];
        if(!get<3>(p[i])) update(1, 0, N, get<1>(p[i]), get<2>(p[i])-1, 1);
        else update(1, 0, N, get<1>(p[i]), get<2>(p[i])-1, -1);
    }
    printf("%lld", sol);
    return 0;
}