#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > v;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { int x, y; scanf("%d %d", &x, &y); v.push_back({ x,y }); }
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
	return 0;
}