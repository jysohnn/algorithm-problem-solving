#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
int n, d;
vector<pii> v;
priority_queue<pii, vector<pii>, greater<pii> > q;

bool comp(pii& x, pii& y)
{
	if (x.second < y.second) return 1;
	else if (x.second > y.second) return 0;
	else return x.first < y.first;
}

int main()
{
	int sol = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if (x > y) swap(x, y);
		v.push_back(make_pair(x, y));
	}
	scanf("%d", &d);
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
	{
		if (v[i].second - v[i].first <= d) q.push(v[i]);
		while (!q.empty() && q.top().first < v[i].second - d) q.pop();
		sol = max(sol, (int)q.size());
	}
	printf("%d", sol);
}