#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
string a, b;
ll x = 0, y = 0, sol;
vector<int> v;

int main()
{
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++) x *= 2, x += (a[i] - '0');
	for (int i = 0; i < b.size(); i++) y *= 2, y += (b[i] - '0');
	sol = x * y;
	while (sol) v.push_back(sol % 2), sol /= 2;
	for (auto it = v.rbegin(); it != v.rend(); it++) printf("%d", *it);
	return 0;
}