#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll N = 100002;
ll t, n;
ll a[N], p[N];
bool c[N];

ll find(ll x)
{
	if(p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}
void merge(ll x, ll y)
{
	x = find(x); y = find(y);
	if(x == y) return;
	p[x] += p[y];
	p[y] = x;
}

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        memset(p, -1, sizeof(p));
        memset(c, 0, sizeof(c));

        ll sol = 0;
        scanf("%lld", &n);
        for(ll i=1; i<=n; i++) scanf("%lld", a+i);
        for(ll i=1; i<=n; i++)
        {
            if(find(i) == find(a[i]))
            {
                c[i] = 1;
                ll j = a[i];
                while(j != i)
                {
                    c[j] = 1;
                    j = a[j];
                }
            }
            merge(i, a[i]);
        }
        for(ll i=1; i<=n; i++)
            if(!c[i]) sol++;
        printf("%lld\n", sol);
    }
    return 0;
}