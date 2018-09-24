#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
ll a, b; string c;

int main()
{
	cin >> a >> b >> c;
	if ((c[c.size() - 1] - '0') % 2 == 0) cout << a;
	else cout << (a^b);
	return 0;
}