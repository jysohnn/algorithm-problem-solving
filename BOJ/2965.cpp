#include <cstdio>
#include <algorithm>

using namespace std;

int x, y, z;
int d[100][100][100];

int solve(int a, int b, int c)
{
	int ret = 0;
	if (d[a][b][c] != -1) return d[a][b][c];
	for (int i = b + 1; i < c; i++)
		ret = max(ret, 1 + solve(b, i, c));
	for (int i = a + 1; i < b; i++)
		ret = max(ret, 1 + solve(a, i, b));
	d[a][b][c] = ret;
	return ret;
}

int main()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++) d[i][j][k] = -1;
	scanf("%d %d %d", &x, &y, &z);
	printf("%d",solve(x, y, z));
	return 0;
}