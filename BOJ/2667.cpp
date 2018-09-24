#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[26][26];
bool v[26][26] = { 0 };
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
vector<int> sol;

bool bc(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
int dfs(int x, int y)
{
	int ret = 1;
	v[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (bc(nx, ny) && !v[nx][ny] && a[nx][ny]) ret += dfs(nx, ny);
	}
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%1d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] && !v[i][j]) sol.push_back(dfs(i, j));
	sort(sol.begin(), sol.end());
	cout << sol.size() << '\n';
	for (int i = 0; i < sol.size(); i++) printf("%d\n", sol[i]);
	return 0;
}