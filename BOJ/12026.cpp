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

const ll INF = 1000000001;
ll n, dp[1001];
map<char, char> p = { {'B','J'}, {'O','B'}, {'J','O'} };
string s;

ll solve(ll x)
{
	ll ret = INF;
	if (dp[x] != -1) return  dp[x];
	if (x == 0) return dp[x] = 0;
	for (int i = 0; i < x; i++)
		if (s[i] == p[s[x]]) ret = min(ret, solve(i) + (x - i)*(x - i));
	return dp[x] = ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> s;
	ll sol = solve(n - 1);
	if (sol < INF) cout << sol;
	else cout << "-1";
	return 0;
}