#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a[100001];
ll n;

ll solve(ll s, ll e)
{
	ll ret;
	ll mid = (s + e) / 2;
	ll l = mid - 2, r = mid + 1;
	ll w, h;
	if (s == e - 1) return a[s];
	h = min(a[mid - 1], a[mid]), w = 2;
	ret = h * w;

	while (s <= l || r < e)
	{
		ll tmp;
		if (s <= l && r < e) tmp = max(a[l], a[r]), a[l] > a[r] ? l-- : r++;
		else if (s <= l) tmp = a[l], l--;
		else  tmp = a[r], r++;
		h = min(h, tmp);
		ret = max(ret, h * ++w);
	}
	return max(ret, max(solve(s, mid), solve(mid, e)));
}

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	cout << solve(0, n);
	return 0;
}