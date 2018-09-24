#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, m;
ll a[2][101][101];

int main()
{
	cin >> n >> m;
	for (ll k = 0; k < 2; k++)
		for (ll i = 0; i < n; i++)
			for (ll j = 0; j < m; j++) scanf("%lld", &a[k][i][j]);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++) a[0][i][j] += a[1][i][j], printf("%lld ", a[0][i][j]);
		putchar('\n');
	}
	return 0;
}