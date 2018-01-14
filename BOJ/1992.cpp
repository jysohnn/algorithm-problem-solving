#include <iostream>

using namespace std;

int n;
int a[64][64];

void solve(int l, int r, int u, int d)
{
	if (l == r || u == d) return;
	bool check = 0;
	int color = a[u][l];
	for (int i = u; i < d; i++)
		for (int j = l; j < r; j++)
			if (a[i][j] != color) { check = 1; break; }
	if (check)
	{
		int midh = (l + r) / 2, midv = (u + d) / 2;
		printf("(");
		solve(l, midh, u, midv);
		solve(midh, r, u, midv);
		solve(l, midh, midv, d);
		solve(midh, r, midv, d);
		printf(")");
	}
	else printf("%d", color);
}

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%1d",&a[i][j]);
	solve(0, n, 0, n);
	return 0;
}