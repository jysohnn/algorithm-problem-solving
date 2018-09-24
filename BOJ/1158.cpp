#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) v.push_back(i+1);
	cout << '<';
	while (!v.empty())
	{
		int rot = m % v.size();
		rotate(v.begin(), v.begin() + rot, v.end());
		cout << v.back(); v.pop_back();
		if (v.size() != 0) cout << ", ";
	}
	cout << '>';
	return 0;
}