#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using vvc = vector<vector<char>>;

int n, m, sol = 11;
char f[11][11];

bool bc(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

int up(char f[11][11], int& rx, int& ry, int& bx, int& by)
{
	int ret = 0;
	const int dx = -1, dy = 0;
	if (rx < bx)
	{
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
	}
	else
	{
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
	}
	return ret;
}
int down(char f[11][11], int& rx, int& ry, int& bx, int& by)
{
	int ret = 0;
	const int dx = 1, dy = 0;
	if (bx < rx)
	{
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
	}
	else
	{
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
	}
	return ret;
}
int left(char f[11][11], int& rx, int& ry, int& bx, int& by)
{
	int ret = 0;
	const int dx = 0, dy = -1;
	if (ry < by)
	{
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
	}
	else
	{
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
	}
	return ret;
}
int right(char f[11][11], int& rx, int& ry, int& bx, int& by)
{
	int ret = 0;
	const int dx = 0, dy = 1;
	if (by < ry)
	{
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
	}
	else
	{
		{
			int& x = bx;
			int& y = by;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret -= 2; break; }
				else break;
			}
		}
		{
			int& x = rx;
			int& y = ry;
			while (1)
			{
				if (bc(x + dx, y + dy) && f[x + dx][y + dy] == '.')
					swap(f[x][y], f[x + dx][y + dy]), x += dx, y += dy;
				else if (f[x + dx][y + dy] == 'O') { f[x][y] = '.', ret += 1; break; }
				else break;
			}
		}
	}
	return ret;
}

void copy(char ff[11][11], char f[11][11])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) ff[i][j] = f[i][j];
}

void solve(char f[11][11], int idx, int rx, int ry, int bx, int by)
{
	if (idx > 10) return;
	for (int i = 0; i < 4; i++)
	{
		char ff[11][11];
		copy(ff, f);
		int rrx = rx, rry = ry, bbx = bx, bby = by;
		int ret;
		switch (i)
		{
		case 0: ret = up(ff, rrx, rry, bbx, bby); break;
		case 1: ret = down(ff, rrx, rry, bbx, bby); break;
		case 2: ret = left(ff, rrx, rry, bbx, bby); break;
		case 3: ret = right(ff, rrx, rry, bbx, bby); break;
		}
		if (ret == 1) sol = min(sol, idx);
		else if(ret == 0) solve(ff, idx + 1, rrx, rry, bbx, bby);
	}
}

int main()
{
	int rx, ry, bx, by;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string x; cin >> x;
		for (int j = 0; j < m; j++)
		{
			f[i][j] = x[j];
			if (x[j] == 'R') rx = i, ry = j;
			if (x[j] == 'B') bx = i, by = j;
		}
	}
	solve(f, 1, rx, ry, bx, by);
	if (sol > 10) cout << "-1";
	else cout << sol;
	return 0;
}