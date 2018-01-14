#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, sol = 0;
ll t[16], p[16];

void solve(int k, ll pp)
{
	if (k >= n) return;
	if(k + 1 <= n) sol = max(sol, pp), solve(k + 1, pp);
	if(k + t[k] <= n) sol = max(sol, pp + p[k]), solve(k + t[k], pp + p[k]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld %lld", t + i, p + i);
	solve(0, 0);
	cout << sol;
	return 0;
}