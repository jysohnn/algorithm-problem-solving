#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
int a[14];
vector<int> sol;

void solve(int idx)
{
	if (idx >= n) return;
	sol.push_back(a[idx]);
	if(sol.size() == 6)
	{
		for (int i = 0; i < sol.size(); i++) printf("%d ", sol[i]);
		putchar('\n');
	}
	solve(idx + 1);
	sol.pop_back();
	solve(idx + 1);
}

int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		sol.clear(); solve(0); putchar('\n');
	}
	return 0;
}