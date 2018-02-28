#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll t, sol;
string s;
vector<bool> v;

int main()
{
	cin >> t;
	while (t--)
	{
		sol = 0; v.clear();
		cin >> s;
		for (int i = 0; i < s.size(); i++) v.push_back((bool)(s[i] - '0'));
		for (int i = 1; i < v.size(); i++) v[i] = v[i] ^ v[i - 1];
		for (int i = 0; i < v.size(); i++) sol *= 2, sol += (int)v[i];
		printf("%lld\n", sol);
	}
	return 0;
}