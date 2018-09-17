#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, a, b;

int main()
{
    ll sol = 1;
    cin>>n>>a>>b;
    while(1)
    {
        if(a % 2 == 0 && b == a-1) break;
        if(b % 2 == 0 && a == b-1) break;
        a = (a+1) / 2;
        b = (b+1) / 2;
        sol++;
    }
    cout<<sol;
    return 0;
}