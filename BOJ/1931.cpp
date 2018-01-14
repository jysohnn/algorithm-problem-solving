#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n;
pll a[100001];
vector<pll> sol;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
	sort(a, a + n, greater<pll>());
	for (int i = 0; i < n; i++)
	{
		if (sol.empty()) sol.push_back(a[i]);
		else if (sol[sol.size() - 1].first >= a[i].second) sol.push_back(a[i]);
	}
	cout << sol.size();
	return 0;
}