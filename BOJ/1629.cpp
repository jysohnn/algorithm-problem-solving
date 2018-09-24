#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll a, b, c;

ll sol(ll a, ll b)
{
    if(b == 0) return 1 % c;

    ll tmp = sol(a, b/2) % c;

    if(b % 2 == 0) return (tmp * tmp) % c;
    else return ((tmp * tmp) % c) * (a % c) % c;
}

int main()
{
    cin>>a>>b>>c;
    cout<<sol(a, b) % c;
    return 0;
}