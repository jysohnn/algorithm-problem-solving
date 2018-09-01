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
vector<int> sol;

int main()
{
	int tmp = 0, ttmp = 1;
	cin >> s;
	if (s == string("0"))
	{
		cout << "0";
		return 0;
	}
	for (int i = s.size() - 1; i >= 0; i--)
	{
		tmp += (s[i] - '0') * ttmp;
		ttmp *= 2;
		if (ttmp == 8) sol.push_back(tmp), tmp = 0, ttmp = 1;
	}
	if (tmp) sol.push_back(tmp);
	for (int i = sol.size()-1; i >= 0; i--) printf("%d", sol[i]);
	return 0;
}