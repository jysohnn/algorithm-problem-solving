#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
ll t;
ll m,n,x,y;

ll gcd (ll x, ll y )
{
  ll z;
  while ( x != 0 ) { z = x; x = y%x; y = z; }
  return y;
}

int main()
{
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld", &m,&n,&x,&y);
		ll g = gcd(m,n); g = m / g;
		ll sol = -1;
		y -= x;
		for(ll i=0;i<=g+1;i++)
			if((n*i + y) % m == 0) {sol = i; break;}
		if(sol == -1) printf("-1\n");
		else printf("%lld\n", n*sol+y+x);
	}
	return 0;
}