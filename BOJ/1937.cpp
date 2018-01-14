#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, sol = 0;
int a[501][501];
int d[501][501];
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };

bool bc(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n) return true;
	else return false;
}

int solve(int x, int y)
{
	int ret = 0;
	if (d[x][y] != -1) return d[x][y];
	for (int i = 0; i < 4; i++)
		if (bc(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] < a[x][y])
			ret = max(ret, solve(x + dx[i], y + dy[i]));
	return d[x][y] = ret + 1;
}

int main()
{
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) sol = max(sol, solve(i, j));
	printf("%d", sol);
	return 0;
}