#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll N = 100000;
const ll INF = 1000000002;
ll a1[4*N + 1];
ll a2[4*N + 1];
ll n, m;

void update1(ll n, ll nl, ll nr, ll i, ll v)
{
	if(i > nr || i < nl) return;
	else if(nl == nr) a1[n] = min(a1[n], v);
	else
	{
		ll mid = (nl + nr) / 2;
		update1(2*n, nl, mid, i, v);
		update1(2*n+1, mid+1, nr, i, v);
		a1[n] = min(a1[2*n], a1[2*n+1]);
	}
}

ll query1(ll n, ll nl, ll nr, ll l, ll r)
{
	if(r < nl || nr < l) return INF;
	else if(l <= nl && nr <= r) return a1[n];
	else
	{
		ll mid = (nl + nr) / 2;
		return min (query1(2*n, nl, mid, l, r), query1(2*n+1, mid + 1, nr, l, r));
	}
}

void update2(ll n, ll nl, ll nr, ll i, ll v)
{
	if(i > nr || i < nl) return;
	else if(nl == nr) a2[n] = max(a2[n], v);
	else
	{
		ll mid = (nl + nr) / 2;
		update2(2*n, nl, mid, i, v);
		update2(2*n+1, mid+1, nr, i, v);
		a2[n] = max(a2[2*n], a2[2*n+1]);
	}
}

ll query2(ll n, ll nl, ll nr, ll l, ll r)
{
	if(r < nl || nr < l) return 0;
	else if(l <= nl && nr <= r) return a2[n];
	else
	{
		ll mid = (nl + nr) / 2;
		return max (query2(2*n, nl, mid, l, r), query2(2*n+1, mid + 1, nr, l, r));
	}
}

int main()
{
	for(int i=0; i<4*N + 1; i++) a1[i] = INF, a2[i] = 0;

	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++)
	{
		ll x; scanf("%lld", &x);
		update1(1, 0, n-1, i, x);
		update2(1, 0, n-1, i, x);
	}
	for(int i=0; i<m; i++)
	{
		ll l, r; scanf("%lld %lld", &l, &r); l--; r--;
		printf("%lld %lld\n", query1(1, 0, n-1, l, r), query2(1, 0, n-1, l, r));
	}
	return 0;
}