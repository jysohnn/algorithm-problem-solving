#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

set<ll> s;
ll n;

int main()
{
    ll x = 1;
    for(int i=0; i<32; i++)
    {
        s.insert(x);
        x = x << 1;
    }
    cin>>n;
    for(int i=0; i<n; i++)
    {
        ll y; scanf("%lld", &y);
        if(s.find(y) != s.end()) printf("1\n");
        else printf("0\n");
    }
    return 0;
}