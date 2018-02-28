#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int map[9][9];
vector<pii> blank;

vector<int> promising(int x, int y)
{
	vector<int> ret;
	int bx = x / 3, by = y / 3;
	bool check[10] = { 0 };
	for (int i = 0; i < 9; i++) check[map[x][i]] = 1, check[map[i][y]] = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) check[map[bx * 3 + i][by * 3 + j]] = 1;
	for (int i = 1; i < 10; i++) if (!check[i]) ret.push_back(i);
	return ret;
}

bool solve(int k)
{
	int x = blank[k].first, y = blank[k].second;
	vector<int> p = promising(x, y);
	for (int i = 0; i < p.size(); i++)
	{
		map[x][y] = p[i];
		if (k == blank.size() - 1) return 1;
		if (solve(k + 1)) return 1;
	}
	map[x][y] = 0;
	return 0;
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			scanf("%1d", &map[i][j]);
			if (!map[i][j]) blank.push_back(pii(i, j));
		}
	solve(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) printf("%d", map[i][j]);
		putchar('\n');
	}
	return 0;
}