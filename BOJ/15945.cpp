#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, idx = 0;
ll a[100001];
ll p = 0, m = 0, z = 0;

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        ll x;
        scanf("%lld", &x);
        if(x > 0) p++, a[idx++] = x;
        else if(x == 0) z++;
        else m++, a[idx++] = x;
    }
    if(z == n) cout<<0;
    else if(p && m) cout<<0;
    else
    {
        for(int i = 0; i < idx; i++) a[i] = abs(a[i]);
        sort(a, a+idx);
        cout<<min(a[0], a[idx-1] - a[0]);
    }
    return 0;
}