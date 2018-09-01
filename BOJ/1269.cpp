#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m, sol = 0;
ll a[200001];
set<ll> b;

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++) scanf("%lld", a+i);
    for(int j=0; j<m; j++)
    {
        ll x; scanf("%lld", &x);
        b.insert(x);
    }
    for(int i=0; i<n; i++)
        if(b.find(a[i]) != b.end()) sol++;
    for(int i=0; i<n; i++)
        if(b.find(a[i]) == b.end()) b.insert(a[i]);
    cout<<b.size()-sol;
    return 0;
}