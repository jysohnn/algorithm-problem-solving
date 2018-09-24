#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, m;
ll l, r;
ll a[100001];
ll up[100001];
ll down[100001];

ll u(ll l, ll r)
{
	l--;
	if(l < 0) return up[r];
	if(a[l] < a[l+1]) return up[r] - up[l] + 1;
	else return up[r] - up[l];
}
ll d(ll l, ll r)
{
	l--;
	if(l < 0) return down[r];
	if(a[l] > a[l+1]) return down[r] - down[l] + 1;
	else return down[r] - down[l];
}

int main()
{
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++) scanf("%lld", a+i);
	
	up[0] = down[0] = 1;
	for(int i=1; i<n; i++)
	{
		if(a[i-1] < a[i]) up[i] = up[i-1];
		else up[i] = up[i-1] + 1;
	}
	for(int i=1; i<n; i++)
	{
		if(a[i-1] > a[i]) down[i] = down[i-1];
		else down[i] = down[i-1] + 1;
	}

	for(int i=0; i<m; i++)
	{
		ll sol;
		scanf("%lld %lld", &l, &r); l--; r--;
		sol = u(0, l-1) + d(l, r) + u(r+1, n-1);

		if(l > 0 && a[l-1] < a[r]) sol--;
		if(r < n-1 && a[l] < a[r+1]) sol--;

		printf("%lld\n", sol);
	}
	return 0;
}