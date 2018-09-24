#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll e, f, c, sol = 0;

int main()
{
	cin >> e >> f >> c;
	e += f;
	while (e / c != 0)
	{
		ll tmp = e / c;
		sol += tmp;
		e %= c; e += tmp;
	}
	cout << sol;
	return 0;
}