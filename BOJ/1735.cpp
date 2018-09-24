#include <iostream>

using namespace std;
using ll = long long;

ll a, b, c, d;
ll x, y;

ll gcd(ll x, ll y)
{
	if(x % y == 0) return y;
	return gcd(y, x % y);
}

int main()
{
	cin>>a>>b>>c>>d;
	x = a * d + b * c;
	y = b * d;
	cout<<x/gcd(x,y)<<" "<<y/gcd(x,y);
	return 0;
}
