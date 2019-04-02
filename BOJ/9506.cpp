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
    while(1)
    {
        ll sum = 0;
        vector<ll> v;
        scanf("%lld", &n);
        if(n == -1) break;
        for(ll i=1; i<n; i++)
            if(n % i == 0) v.push_back(i), sum += i;
        if(sum == n)
        {
            printf("%lld = ", n);
            for(ll i=0; i<v.size(); i++)
            {
                if(i != 0) printf(" + ");
                printf("%lld", v[i]);
            }
            printf("\n");
        }
        else printf("%lld is NOT perfect.\n", n);
    }
    return 0;
}