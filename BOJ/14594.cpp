#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll n, m, p[101], sol = 0;

int find(int x)
{
	if (p[x] == -1) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y)
{
	x = find(x); y = find(y);
	p[x] = y;
}

int main()
{
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y); x--; y--;
		for (int j = x; j < y; j++)
			if (find(j) != find(j+1)) merge(j, j+1);
	}
	for (int i = 0; i < n; i++)
		if (p[i] == -1) sol++;
	cout << sol;
	return 0;
}