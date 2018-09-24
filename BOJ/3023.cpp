#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, m, x, y;
char p[101][101];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		getchar();
		for (int j = 0; j < m; j++)
		{
			p[i][j] = getchar();
			p[2*n-i-1][j] = p[i][j];
			p[i][2*m-j-1] = p[i][j];
			p[2*n-i-1][2*m-j-1] = p[i][j];
		}
	}
	cin >> x >> y; x--; y--;
	if (p[x][y] == '.') p[x][y] = '#';
	else p[x][y] = '.';
	for (int i = 0; i < 2 * n; i++)
	{
		for (int j = 0; j < 2 * m; j++) putchar(p[i][j]);
		putchar('\n');
	}
	return 0;
}