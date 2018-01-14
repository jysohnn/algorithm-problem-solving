#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, int> > v;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (s == string("order"))
		{
			int x, y;
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(y, x));
		}
		else if (s == string("sort")) sort(v.begin(), v.end());
		else if (s == string("complete"))
		{
			int x; scanf("%d",&x);
			for (auto it = v.begin(); it != v.end(); it++)
				if (it->second == x)
				{
					v.erase(it);
					break;
				}
		}
		if (v.empty()) printf("sleep");
		else for (int i = 0; i < v.size(); i++) printf("%d ", v[i].second); 
		putchar('\n');
	}
	return 0;
}