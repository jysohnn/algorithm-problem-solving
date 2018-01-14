#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll n, g, x;
vector<ll> sol;

ll gcd(ll x, ll y)
{
	if (x % y == 0) return y;
	else return gcd(y, x % y);
}

int main()
{
	cin >> n >> g;
	for (int i = 0; i < n - 1; i++) scanf("%lld", &x), g = gcd(g, x);
	for (int i = 1; i <= (ll)sqrt(g); i++)
		if (g % i == 0) sol.push_back(i), sol.push_back(g / i);
	sort(sol.begin(), sol.end());
	for (int i = 0; i < sol.size(); i++)
		if(i == 0 || sol[i-1] != sol[i]) printf("%lld\n", sol[i]);
	return 0;
}