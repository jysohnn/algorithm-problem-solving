#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> v;

int main()
{
	for (int i = 0; i < 20; i++) v.push_back(i + 1);
	for (int i = 0; i < 10; i++)
	{
		int x, y; cin >> x >> y;
		reverse(v.begin() + x - 1, v.begin() + y);
	}
	for (int x : v) cout << x << ' ';
	return 0;
}