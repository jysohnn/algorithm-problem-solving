#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
vector<int> sol;
bool v[9] = { 0 };

void solve(int i)
{
	if (sol.size() == n)
	{
		for (int i = 0; i < sol.size(); i++) printf("%d ", sol[i]);
		putchar('\n');
	}
	for (int i = 1; i <= n; i++)
		if(!v[i])
		{
			v[i] = 1; sol.push_back(i);
			solve(i - 1);
			v[i] = 0; sol.pop_back();
		}
}

int main()
{
	cin >> n;
	solve(n);
	return 0;
}