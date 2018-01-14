#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll n;

ll solve(ll x)
{
	if (x == 1) return 0;
	if (x == 2) return 1;
	if (x % 2 == 0) return (x / 2)*(x / 2) + 2 * solve(x / 2);
	else return (x / 2)*(x / 2 + 1) + solve(x / 2) + solve(x / 2 + 1);
}

int main()
{
	cin >> n;
	cout << solve(n);
	return 0;
}