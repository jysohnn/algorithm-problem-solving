#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> line;
line one, two;

int ccw(pll& a, pll& b, pll& c)
{
	ll ret = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	if (ret > 0) return 1;
	if (ret == 0) return 0;
	else return -1;
}

bool check(line& a, line& b)
{
	ll ab = ccw(a.first, a.second, b.first)
		* ccw(a.first, a.second, b.second);
	ll ba = ccw(b.first, b.second, a.first)
		* ccw(b.first, b.second, a.second);
	if (ab == 0 || ba == 0) return 0;
	return ab < 0 && ba < 0;
}

int main()
{
	pll a[4];
	ll x, y, z, l;
	cin >> x >> y >> z >> l;
	a[0] = pll(x, y); a[1] = pll(z, l);
	one = line(a[0], a[1]);
	cin >> x >> y >> z >> l;
	a[2] = pll(x, y); a[3] = pll(z, l);
	two = line(a[2], a[3]);
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4;j++)
			if (a[i] == a[j])
			{
				cout << 0;
				return 0;
			}
	if (check(one, two)) cout << 1;
	else cout << 0;
	return 0;
}