#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

string a, b;
ll dp[1001][1001];
ll sol = 0;

ll solve(ll x, ll y)
{
	if (x >= a.size() || y >= b.size()) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (a[x] != b[y]) return dp[x][y] = max(solve(x + 1, y), solve(x, y + 1));
	else return dp[x][y] = solve(x + 1, y + 1) + 1;
}

string solve2(ll x, ll y)
{
	if (x >= a.size() || y >= b.size()) return string();
	if (a[x] != b[y])
	{
		if (solve(x + 1, y) > solve(x, y + 1)) return solve2(x + 1, y);
		else return solve2(x, y + 1);
	}
	else
	{
		string tmp;
		tmp.push_back(a[x]);
		return tmp + solve2(x + 1, y + 1);
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	cout << solve(0, 0) << '\n';
	cout << solve2(0, 0);
	return 0;
}