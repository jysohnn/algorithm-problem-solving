#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x; scanf("%lld", &x);
    }
    if(n == 0) printf("divide by zero");
    else printf("1.00");
    return 0;
}