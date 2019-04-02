#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll l, a, b, c, d;
ll x, y;

int main()
{
    cin>>l>>a>>b>>c>>d;
    x = a / c;
    if(a % c) x++;
    y += b / d;
    if(b % d) y++;
    cout<<l - max(x, y);
    return 0;
}