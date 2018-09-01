#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll t, a, b;

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a + b);
    }
    return 0;
}