#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
ll h, w;
ll c[501][501], sol[6][201];

ll combi(int x, int y)
{
	if (c[x][y] != -1) return c[x][y];
	if (x == 0 && y == 0) return c[x][y] = 1;
	if (x == y) return c[x][y] = 1;
	if (y == 0) return c[x][y] = 1;
	c[x][y] = (combi(x - 1, y) + combi(x - 1, y - 1)) % MOD;
	return c[x][y];
}

ll solve(int x, int y)
{
	ll ret = 0;
	if (sol[x][y] != -1) return sol[x][y];
	if (x == 0) return sol[x][y] = 1;
	for (int i = 1; i <= w; i++)
		ret += combi(y + i - 1, i) * solve(x - 1, i), ret %= MOD;
	return sol[x][y] = ret;
}

int main()
{
	memset(c, -1, sizeof(c));
	memset(sol, -1, sizeof(sol));
	cin >> h >> w;
	cout << solve(h, 1);
	return 0;
}