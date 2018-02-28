#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, a, b;

ll gcd(ll x, ll y)
{
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}

int main()
{
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld %lld\n", a * b / gcd(a, b), gcd(a, b));
	}
	return 0;
}