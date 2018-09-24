#include <iostream>

using namespace std;

bool sol = 0;
int n, m;
int a[1001][1001];
bool v[1001][1001] = { 0 };
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

bool bc(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }
void dfs(int x, int y)
{
	v[x][y] = 1;
	if (x == n - 1) sol = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (bc(nx, ny) && !v[nx][ny] && !a[nx][ny]) dfs(nx, ny);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%1d",&a[i][j]);
	for (int j = 0; j < m; j++) if(!a[0][j]) dfs(0, j);
	if (sol) cout << "YES"; else cout << "NO";
	return 0;
}