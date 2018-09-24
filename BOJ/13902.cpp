#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
ll n, m;
bool num[10001] = { 0 };
ll d[10001];
vector<ll> v;

int main()
{
	cin >> n >> m;
	fill(d, d + n + 1, 999999); d[0] = 0;
	for (int i = 0; i < m; i++)
	{
		ll x; scanf("%lld", &x);
		v.push_back(x);
	}
	for (int i = 0; i < v.size(); i++)
		for (int j = i + 1; j < v.size(); j++)
			if (v[i] + v[j] <= n) num[v[i] + v[j]] = 1;
	for (int i = 0; i <= n; i++)
		if (num[i]) v.push_back(i);
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j <= n; j++)
			if (j + v[i] <= n && d[j + v[i]] > d[j] + 1) d[j + v[i]] = d[j] + 1;
	if (d[n] >= 999999) printf("-1");
	else printf("%lld",d[n]);

	return 0;
}