#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> line;

int ccw(pll a, pll b, pll c)
{
	ll ret = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

int main()
{
	pll a[3];
	for (int i = 0; i < 3; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		a[i].first = x;
		a[i].second = y;
	}
	printf("%d", ccw(a[0], a[1], a[2]));
	return 0;
}