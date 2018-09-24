#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
typedef pair<int, int> pii;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };
int n, k, l, d = 0;
int a[101][101] = { 0 };
int dir[10001] = { 0 };
deque<pii> q;

bool bc(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return 0;
	if (a[x][y] == 2) return 0;
	return 1;
}

int main()
{
	int sol = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		a[--x][--y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int x; char y;
		scanf("%d %c", &x, &y);
		if (y == 'D') dir[x] = 1;
		else dir[x] = -1;
	}

	a[0][0] = 2;
	q.push_front(pii(0, 0));

	while (1)
	{
		pii p = q.front();
		int x = p.first, y = p.second;
		int nx = x + dx[d];
		int ny = y + dy[d];

		d = (d + dir[sol] + 4) % 4;

		if (bc(nx, ny))
		{
			if (a[nx][ny] != 1)
			{
				pii pp = q.back(); q.pop_back();
				int ex = pp.first, ey = pp.second;
				a[ex][ey] = 0;
			}

			a[nx][ny] = 2;
			q.push_front(pii(nx, ny));
		}
		else break;
		sol++;
	}
	cout << sol;
}