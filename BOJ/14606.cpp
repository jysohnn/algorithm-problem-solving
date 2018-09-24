#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll n, d[11];

ll solve(ll x)
{
	if (d[x] != -1) return d[x];
	if (x == 1) return d[x] = 0;
	if (x == 2) return d[x] = 1;
	if (x % 2 == 0) return d[x] = (x / 2)*(x / 2) + solve(x / 2) + solve(x / 2);
	else return d[x] = (x / 2)*(x / 2 + 1) + solve(x / 2) + solve(x / 2 + 1);
}

int main()
{
	memset(d, -1, sizeof(d));
	cin >> n;
	cout << solve(n);
	return 0;
}