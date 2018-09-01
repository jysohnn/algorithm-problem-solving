#include <stdio.h>

int row, col;
char map[20][20];
int sol = 0;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 }; //위 왼 아래 오른
int v[26] = { 0 }; //0~25 : A ~ Z

bool bc(int x, int y) { return x >= 0 && x < row && y >= 0 && y < col; }
void solve(int x, int y, int n)
{
	if (sol < n) sol = n;

	v[map[x][y] - 'A'] = 1;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dr[k];
		int ny = y + dc[k];
		if (bc(nx, ny) && !v[map[nx][ny] - 'A'])
			solve(nx, ny, n + 1);
	}
	v[map[x][y] - 'A'] = 0;
}

int main() {

	scanf("%d %d", &row, &col);  getchar();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) scanf("%c", &map[i][j]);
		getchar();
	}
	solve(0, 0, 1);
	printf("%d\n", sol);
}