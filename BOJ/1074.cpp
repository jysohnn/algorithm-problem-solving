#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, x, y;

ll solve(ll n, ll x, ll y)
{
	if (n == 0) return 0;
	ll order = (x / (1 << (n - 1)) * 2) + (y / (1 << (n - 1)));
	return order * ((1 << (n-1))*(1 << (n - 1))) + solve(n - 1, x % (1 << (n - 1)), y % (1 << (n - 1)));
}

int main()
{
	cin >> n >> x >> y;
	cout << solve(n, x, y);
	return 0;
}