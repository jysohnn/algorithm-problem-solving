#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a, b, sol = 0;
int m[1001][1001];

bool check(int x, int y, int k)
{
	if (m[x][y] == m[x + k - 1][y] && m[x + k - 1][y] == m[x][y + k - 1]
		&& m[x][y + k - 1] == m[x + k - 1][y + k - 1]) return true;
	else return false;
}

int main()
{
	cin >> a >> b;
	memset(m, -1, sizeof(m));
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++) scanf("%1d", &m[i][j]);
	for (int k = 1; k <= min(a, b); k++)
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if (check(i, j, k)) sol = max(sol, k);
	cout << sol * sol;
	return 0;
}