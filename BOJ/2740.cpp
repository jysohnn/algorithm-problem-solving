#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n, m, k;
ll a[101][101], b[101][101], c[101][101] = { 0 };

int main()
{
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++) scanf("%lld", &a[i][j]);
	cin >> m >> k;
	for (ll i = 0; i < m; i++)
		for (ll j = 0; j < k; j++) scanf("%lld", &b[i][j]);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < k; j++)
		{
			for (ll l = 0; l < m; l++) c[i][j] += a[i][l] * b[l][j];
			printf("%lld ", c[i][j]);
		}
		putchar('\n');
	}
	return 0;
}