#include <iostream>

using namespace std;
typedef long long ll;

ll t;
ll sx, sy, ex, ey;
ll cx, cy, cr;

ll sq(ll x) { return x*x; }
bool isin(ll x, ll y) { return sq(cx - x) + sq(cy - y) <= sq(cr); }

int main()
{
	cin >> t;
	while (t--)
	{
		ll n, sol = 0;
		scanf("%lld %lld %lld %lld %lld", &sx, &sy, &ex, &ey, &n);
		while (n--)
		{
			bool s, e;
			scanf("%lld %lld %lld", &cx, &cy, &cr);
			s = isin(sx, sy), e = isin(ex, ey);
			if (s != e) sol++;
		}
		printf("%lld\n", sol);
	}
	return 0;
}