#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll t;

void solve(ll x)
{
	for (int i = 0; x; i++, x/=2)
		if (x % 2 == 1) printf("%d ", i);
	putchar('\n');
}

int main()
{
	cin >> t;
	while (t--)
	{
		ll x; scanf("%lld", &x);
		solve(x);
	}
	return 0;
}