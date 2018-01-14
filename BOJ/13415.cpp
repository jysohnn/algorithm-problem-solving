#include <cstdio>
#include <functional>
#include <deque>
#include <algorithm>

using namespace std;

int n, k;
int a[100001];
deque<pair<int, bool> > d;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	scanf("%d",&k);
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d",&x);
		while (!d.empty() && d.back().first <= x) d.pop_back();
		d.push_back(make_pair(x, 1));
		scanf("%d", &x);
		while (!d.empty() && d.back().first <= x) d.pop_back();
		d.push_back(make_pair(x, 0));
	}
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i].second) sort(a, a + d[i].first);
		else sort(a, a + d[i].first, greater<int>());
	}
	for (int i = 0; i < n; i++) printf("%d ",a[i]);
	return 0;
}