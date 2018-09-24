#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const ll MOD = 9999991;
ll t, n;
ll c[21][21];
int a[21], p[21], l[21], r[21];
int ln[21], rn[21];

ll com(int x, int y)
{
	if (x < 0 || y < 0) return 0;
	if (x < y) return 0;
	if (c[x][y] != -1) return c[x][y];
	if (y == 0) return c[x][y] = 1;
	if (x == y) return c[x][y] = 1;
	
	return c[x][y] = (com(x - 1, y) + com(x - 1, y - 1)) % MOD;
}

ll h(int x, int y)
{
	return com(x + y - 1, y);
}

void insert(int root, int data)
{
	if (root < data)
	{
		if (r[root] == -1) r[root] = data, p[data] = root;
		else insert(r[root], data);
	}
	else
	{
		if (l[root] == -1) l[root] = data, p[data] = root;
		else insert(l[root], data);
	}
}

ll count(int x)
{
	if (x == -1) return 0;
	return count(l[x]) + count(r[x]) + 1;
}

ll sol(int x)
{
	ll ret = 1;
	if(l[x] != -1) ret *= sol(l[x]), ret %= MOD;
	if(r[x] != -1) ret *= sol(r[x]), ret %= MOD;
	ret *= h(max(ln[x], rn[x]) + 1, min(ln[x], rn[x])), ret %= MOD;
	return ret;
}

int main()
{
	memset(c, -1, sizeof(c));
	cin >> t;
	while (t--)
	{
		memset(l, -1, sizeof(l));
		memset(r, -1, sizeof(r));
		memset(ln, -1, sizeof(ln));
		memset(rn, -1, sizeof(rn));

		scanf("%lld", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 1; i < n; i++) insert(a[0], a[i]);
		for (int i = 0; i < n; i++) ln[a[i]] = count(l[a[i]]), rn[a[i]] = count(r[a[i]]);
		printf("%lld\n", sol(a[0]));
	}
	return 0;
}