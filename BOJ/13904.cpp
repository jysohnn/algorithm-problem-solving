#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int n, sol = 0;
pii a[1001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d",&x, &y);
		a[i].first = x;
		a[i].second = y;
	}
	sort(a, a + n, greater<pii>());
	int maxd = a[0].first;
	for(int i=maxd;i>0;i--)
	{
		int m = 0, idx = -1;
		for (int j = 0; j < n; j++)
			if (a[j].first >= i && m < a[j].second) m = a[j].second, idx = j;
		if (idx != -1)
		{
			sol += a[idx].second;
			a[idx].second = 0;
		}
	}
	cout << sol;
	return 0;
}