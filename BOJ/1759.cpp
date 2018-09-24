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

ll n, m;
bool v[16] = { 0 };
string s, code;
vector<string> sol;
set<char> o = { 'a', 'i', 'e', 'o', 'u'};

bool promising()
{
	int x = 0, y = 0;
	for (int i = 0; i < code.size(); i++)
	{
		if (o.find(code[i]) != o.end()) y++;
		else x++;
	}
	if (x >= 2 && y >= 1) return true;
	else return false;
}

void solve(int idx)
{
	if (idx >= s.size()) return;
	code.push_back(s[idx]);
	if (code.size() == n && promising())
		sol.push_back(code);
	solve(idx+1);
	code.pop_back();
	solve(idx+1);
}

int main()
{
	string code;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		char c;
		getchar(); c = getchar();
		s.push_back(c);
	}
	sort(s.begin(), s.end());
	solve(0);
	for (int i = 0; i < sol.size(); i++) printf("%s\n", sol[i].c_str());
	return 0;
}