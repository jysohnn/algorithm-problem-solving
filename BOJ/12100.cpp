#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const ll dx[4] = { 1,-1,0,0 }; // 하 상 우 좌
const ll dy[4] = { 0,0,1,-1 };
ll n, sol = 0;
vector<vector<ll> > a;

bool bc(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

ll findMax(vector<vector<ll> >& map)
{
	ll ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) ret = max(ret, map[i][j]);
	return ret;
}

void move(int x, int y, int k, vector<vector<ll> >& map)
{
	while (bc(x + dx[k], y + dy[k]) && !map[x + dx[k]][y + dy[k]])
	{
		swap(map[x][y], map[x + dx[k]][y + dy[k]]);
		x += dx[k], y += dy[k];
	}
}

void merge(int x, int y, int k, vector<vector<ll> >& map)
{
	if (bc(x - dx[k], y - dy[k]) && (map[x][y] == map[x - dx[k]][y - dy[k]])) map[x][y] *= 2, map[x - dx[k]][y - dy[k]] = 0;
}

void solve(vector<vector<ll> > map, int num, int k)
{
	sol = max(sol, findMax(map));
	if (num == 0) return;
	switch (k)
	{
	case 0:
		for (int j = 0; j < n; j++)
			for (int i = n - 1; i >= 0; i--)
				if (map[i][j]) move(i, j, k, map);
		for (int j = 0; j < n; j++)
			for (int i = n - 1; i >= 0; i--)
				if (map[i][j]) merge(i, j, k, map);
		for (int j = 0; j < n; j++)
			for (int i = n - 1; i >= 0; i--)
				if (map[i][j]) move(i, j, k, map);
		break;
	case 1:
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				if (map[i][j]) move(i, j, k, map);
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				if (map[i][j]) merge(i, j, k, map);
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				if (map[i][j]) move(i, j, k, map);
		break;
	case 2:
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
				if (map[i][j]) move(i, j, k, map);
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
				if (map[i][j]) merge(i, j, k, map);
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j >= 0; j--)
				if (map[i][j]) move(i, j, k, map);
		break;
	case 3:
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j]) move(i, j, k, map);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j]) merge(i, j, k, map);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (map[i][j]) move(i, j, k, map);
		break;
	}
	for (int i = 0; i < 4; i++) solve(map, num - 1, i);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a.push_back(vector<ll>());
		for (int j = 0; j < n; j++)
		{
			ll tmp;
			scanf("%lld", &tmp);
			a[i].push_back(tmp);
		}
	}
	for (int i = 0; i < 4; i++) solve(a, 5, i);
	cout << sol;
	return 0;
}