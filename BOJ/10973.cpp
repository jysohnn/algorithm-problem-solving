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
ll a[10001];

int main()
{
    cin>>n;
    for(ll i = 0; i < n; i++) scanf("%lld", a+i);
    for(ll i = n-1; i >= 1; i--)
    {
        if(a[i-1] > a[i])
        {
            ll max_val = 0, max_idx = i;
            for(ll j = i; j < n; j++)
            {
                if(a[j] < a[i-1] && a[j] > max_val)
                {
                    max_val = a[j];
                    max_idx = j;
                }
            }
            swap(a[i-1], a[max_idx]);
            sort(a+i, a+n, greater<ll>());
            for(ll j = 0; j < n; j++) printf("%lld ", a[j]);
            return 0;
        }
    }
    printf("-1");
    return 0;
}