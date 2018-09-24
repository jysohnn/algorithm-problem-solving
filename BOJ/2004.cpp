#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll a, b;

ll count(ll n, ll x)
{
	ll ret = 0;
	while (n) n /= x, ret += n;
	return ret;
}

int main()
{
	cin >> a >> b;
	ll two = count(a, 2);
	ll five = count(a, 5);
	two -= count(b, 2);
	five -= count(b, 5);
	two -= count(a - b, 2);
	five -= count(a - b, 5);
	cout << min(two, five);
	return 0;
}