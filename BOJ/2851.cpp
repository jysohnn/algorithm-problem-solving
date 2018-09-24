#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;
ll sol = 0;

int main()
{
	for (int i = 0; i < 10; i++)
	{
		ll x; cin >> x;
		if (abs(100 - sol) > abs(100 - (sol + x))) sol += x;
		else if (abs(100 - sol) == abs(100 - (sol + x))) { sol += x; break; }
		else break;
	}
	cout << sol;
	return 0;
}