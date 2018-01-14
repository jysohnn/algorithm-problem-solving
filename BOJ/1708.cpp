#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> line;

int ccw(pll a, pll b, pll c)
{
	ll ret = a.first*b.second + b.first*c.second + c.first*a.second
		- b.first*a.second - c.first*b.second - a.first*c.second;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

ll n;
vector<pll> p; // all point
vector<pll> sol; // convex hull
pll start;

bool comp(pll& a, pll& b)
{
	ll daf = a.first - start.first, das = a.second - start.second;
	ll dbf = b.first - start.first, dbs = b.second - start.second;

	if (das * dbf < daf * dbs) return 1;
	else if (das * dbf > daf * dbs) return 0;
	else if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}
bool yx(pll& a, pll& b)
{
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

void grahams()
{
	sort(p.begin(), p.end(), yx);
	start.first = p[0].first; start.second = p[0].second;
	sort(p.begin() + 1, p.end(), comp);

	sol.push_back(p[0]); sol.push_back(p[1]);
	for (int i = 2; i < p.size(); i++)
	{
		while(sol.size() >= 2)
		{
			pll tmp1 = sol[sol.size() - 1], tmp2 = sol[sol.size() - 2];
			if (ccw(tmp2, tmp1, p[i]) <= 0) sol.pop_back();
			else break;
		}
		sol.push_back(p[i]);
	}
}

int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		p.push_back(pll(x, y));
	}
	grahams();
	printf("%d", sol.size());
	return 0;
}