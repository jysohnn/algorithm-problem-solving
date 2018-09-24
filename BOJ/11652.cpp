#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <functional>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;

ll n, m = 0, c = 0, p = -1, sol;
ll a[1000001];

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (p != a[i])
		{
			if (c > m) m = c, sol = p;
			c = 0;
			p = a[i];
		}
		c++;
	}
	if (c > m) m = c, sol = p;
	printf("%lld", sol);
	return 0;
}