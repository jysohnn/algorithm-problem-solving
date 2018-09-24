#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> v;
const ll INF = 999999999;
ll n, w[11][11], sol = INF;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) v.push_back(i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &w[i][j]);
			if (w[i][j] == 0) w[i][j] = INF;
		}
	do
	{
		ll cost = 0;
		for (int i = 0; i < n - 1; i++) cost += w[v[i]][v[i + 1]];
		cost += w[v[n - 1]][v[0]];
		sol = min(sol, cost);
	} while (next_permutation(v.begin(), v.end()));
	cout << sol;
	return 0;
}