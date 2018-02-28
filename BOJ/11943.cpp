#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

pll a, b;

int main()
{
	cin >> a.first >> a.second >> b.first >> b.second;
	cout << min(a.first + b.second, a.second + b.first);
	return 0;
}