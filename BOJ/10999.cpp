#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll N = 1000000;
ll a[4*N + 1] = { 0 };
ll lazy[4*N + 1] = { 0 };
ll nn, mm, kk;

void update(ll n, ll nl, ll nr, ll l, ll r, ll v)
{
	if(lazy[n])
	{
		a[n] += (nr-nl+1) * lazy[n];
		if(nl!=nr) lazy[2*n] += lazy[n];
		if(nl!=nr) lazy[2*n+1] += lazy[n];
		lazy[n] = 0;
	}

	if(r < nl || nr < l) return;
	else if(l <= nl && nr <= r)
	{
		a[n] += (nr-nl+1) * v;
		if(nl!=nr) lazy[2*n] += v;
		if(nl!=nr) lazy[2*n+1] += v;
	}
	else
	{
		ll mid = (nl + nr) / 2;
		update(2*n, nl, mid, l, r, v);
		update(2*n+1, mid + 1, nr, l, r, v);
		a[n] = a[2*n] + a[2*n+1];
	}
}

ll query(ll n, ll nl, ll nr, ll l, ll r)
{
	if(lazy[n])
	{
		a[n] += (nr-nl+1) * lazy[n];
		if(nl!=nr) lazy[2*n] += lazy[n];
		if(nl!=nr) lazy[2*n+1] += lazy[n];
		lazy[n] = 0;
	}

	if(r < nl || nr < l) return 0;
	else if(l <= nl && nr <= r) return a[n];
	else
	{
		ll mid = (nl + nr) / 2;
		return query(2*n, nl, mid, l, r) + query(2*n+1, mid + 1, nr, l, r);
	}
}

int main()
{
	scanf("%lld %lld %lld", &nn, &mm, &kk);
	for(int i=0; i<nn; i++)
	{
		ll x; scanf("%lld", &x);
		update(1, 0, nn-1, i, i, x);
	}
	for(int i=0; i<mm+kk; i++)
	{
		ll t, l, r, v; scanf("%lld", &t);
		if(t == 1)
		{
			scanf("%lld %lld %lld", &l, &r, &v); l--; r--;
			update(1, 0, nn-1, l, r, v);
		}
		if(t == 2)
		{
			scanf("%lld %lld", &l, &r); l--; r--;
			printf("%lld\n", query(1, 0, nn-1, l, r));
		}
	}
	return 0;
}