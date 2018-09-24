#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long a, b, c, d;

int ssize(int x)
{
	int ret = 1;
	while (x > 9) ret++, x /= 10;
	return ret;
}
long long power(int x)
{
	long long ret = 1;
	while (x--) ret *= 10;
	return ret;
}

int main()
{
	cin >> a >> b >> c >> d;
	a *= power(ssize(b)); a += b;
	c *= power(ssize(d)); c += d;
	cout << a + c;
	return 0;
}