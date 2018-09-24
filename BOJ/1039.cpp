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

ll n, k;
ll dp[1000001][11];

int length(ll n)
{
	int ret = 0;
	while (n) n /= 10, ret++;
	return ret;
}

ll change(ll n, int i, int j)
{
	vector<int> v;
	while (n) v.push_back(n % 10), n /= 10;
	if (j == v.size() - 1 && v[i] == 0) return -1;
	else
	{
		ll ret = 0;
		swap(v[i], v[j]);
		for (int k = v.size()-1; k >= 0; k--) ret *= 10, ret += v[k];
		return ret;
	}
}

ll solve(ll n, ll k)
{
	if (dp[n][k] != -1) return dp[n][k];
	if (k == 0) return dp[n][k] = n;

	ll ret = -2;
	int l = length(n);
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
		{
			ll m = change(n, i, j);
			if (m != -1) ret = max(ret, solve(m, k - 1));
		}
	return dp[n][k] = ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	if (solve(n, k) != -2) cout << solve(n, k);
	else cout << "-1";
	return 0;
}