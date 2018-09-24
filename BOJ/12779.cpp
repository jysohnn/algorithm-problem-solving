#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
ll a, b, n, aa, bb, x;

ll gcd(ll a, ll b)
{
	ll c;
	while (a != 0) {
		c = a; a = b % a;  b = c;
	}
	return b;
}

int main()
{
	cin >> a >> b; n = b - a;
	bb = (ll)sqrt(b); aa = (ll)sqrt(a);
	x = bb - aa;
	if (x == 0) printf("0");
	else
	{
		ll f = gcd(x, n);
		x /= f;
		n /= f;
		printf("%lld/%lld", x, n);
	}
	return 0;
}