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

int n, m, k;
double a[102] = { 0 };
double dp[102][102];

double solve(int x, int y)
{
	if (dp[x][y] != -1.0) return dp[x][y];
	if (x == 0 || y == 0) return dp[x][y] = 0;
	if (x < y) return dp[x][y] = 0;

	return dp[x][y] = max(solve(x-1, y), solve(x-1, y-1) + a[x]);
}

int main()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) dp[i][j] = -1.0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int x; double y;
			scanf("%d %lf", &x, &y);
			a[x] = max(a[x], y);
		}
	printf("%.1lf", solve(n, k));
	return 0;
}