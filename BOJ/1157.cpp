#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <functional>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;

string s;
vector<ll> c(26, 0);

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ('a' <= s[i] && s[i] <= 'z') c[s[i] - 'a']++;
		if ('A' <= s[i] && s[i] <= 'Z') c[s[i] - 'A']++;
	}
	auto m = max_element(c.begin(), c.end());
	ll check = 0; char sol;
	for (int i = 0; i < 26; i++)
		if (c[i] == *m) check++, sol = 'A' + i;
	if (check == 1) cout << sol;
	else cout << '?';
	return 0;
}