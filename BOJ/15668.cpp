#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll x;
vector<ll> v;
bool n[10] = {0};

void make_num(ll x)
{
	v.push_back(x);
	for(int i=0; i<10; i++)
		if(!n[i])
		{
			ll nx = x * 10 + i;
			n[i] = 1;
			if(nx > 0 && nx <= 1000000000) make_num(nx);
			n[i] = 0;
		}
}

bool check(ll s, ll x)
{
	ll y = s - x;
	bool nn[10] = {0};
	
	if(y == 0) return 0;
	while(x)
	{
		if(nn[x%10]) return 0;
		else nn[x%10] = 1, x /= 10;
	}
	while(y)
	{
		if(nn[y%10]) return 0;
		else nn[y%10] = 1, y /= 10;
	}
	return 1;
}

int main()
{
	for(int i=1;i<10;i++)
	{
		n[i] = 1;
		make_num(i);
		n[i] = 0;
	}
	sort(v.begin(), v.end());
	cin>>x;
	for(int i=0; i<v.size() && v[i] <= x; i++)
	{
		if(check(x, v[i]))
		{
			printf("%lld + %lld", v[i], x-v[i]);
			return 0;
		}
	}
	printf("-1");
	return 0;
}