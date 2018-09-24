#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll d[101][101][101], n, sol = 0;
const ll MOD = 10007;
const ll dir[2] = { 0, -1 };

ll solve(int x, int y, int n)
{
	ll ret = 0;
	if (d[x][y][n] != -1) return d[x][y][n];
	if (x == y) return d[x][y][n] = 0;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (x + dir[i] >= 0 && x + dir[i] < n && y + dir[j] >= 0 && y + dir[j] < n)
				ret += solve(x + dir[i], y + dir[j], n - 1), ret %= MOD;
	return d[x][y][n] = ret;
}

int main()
{
	memset(d, -1, sizeof(d));
	d[0][0][0] = 0, d[0][1][1] = 1, d[1][0][1] = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) sol += solve(i,j,n-1), sol %= MOD;
	cout << sol;
}