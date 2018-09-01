#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[1000001];
ll n, m, x = 0;

ll check(ll x)
{
	ll ret = 0;
	for (int i = 0; i < n; i++) ret += max((ll)0, a[i] - x);
	return ret;
}

ll bc(ll s, ll e)
{
	ll mid = (s + e) / 2;
	ll ret = check(mid);
	if (s > e) return -1;
	if (ret < m) return bc(s, mid - 1);
	else return max(mid, bc(mid + 1, e));
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	cout << bc(0, 2000000001);
	return 0;
}