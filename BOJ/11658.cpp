#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, m;
ll a[1026][1026] = { 0 };
ll t[1026][1026] = { 0 };

void update(ll x, ll y, ll v)
{
	for(ll xx = x; xx <= n; xx += (xx & -xx))
		for(ll yy = y; yy <= n; yy += (yy & -yy))
			t[xx][yy] += v;
}
ll query(ll x, ll y)
{
	ll ret = 0;
	for(ll xx = x; xx; xx -= (xx & -xx))
		for(ll yy = y; yy; yy -= (yy & -yy))
			ret += t[xx][yy];
	return ret;
}
ll sol(ll x, ll y, ll xx, ll yy)
{
	x--; y--;
	return query(xx, yy) - query(x, yy) - query(xx, y) + query(x, y);
}

int main()
{
	scanf("%lld %lld", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			scanf("%lld", &a[i][j]);
			update(i, j, a[i][j]);
		}
	for(int i=0; i<m; i++)
	{
		ll w, x, y, z, e;
		scanf("%lld", &w);
		if(w == 0)
		{
			ll v;
			scanf("%lld %lld %lld", &x, &y, &z);
			v = z - a[x][y];
			a[x][y] = z;
			update(x, y, v);
		}
		else
		{
			scanf("%lld %lld %lld %lld", &x, &y, &z, &e);
			printf("%lld\n", sol(x, y, z, e));
		}
	}
	return 0;
}