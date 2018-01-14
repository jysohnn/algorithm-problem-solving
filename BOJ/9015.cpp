#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
int t, n;
vector<pii> p;
set<int> s[20002];

bool bc(int x, int y)
{
	if (x >= 0 && x < 20001 && y >= -10000 && y < 10001) return 1;
	else return 0;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int sol = 0;
		p.clear();
		for (int i = 0; i < 20002; i++) s[i].clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x, y; scanf("%d %d",&x,&y);
			p.push_back(pii(x, y));
			if (s[x + 10000].find(y) == s[x + 10000].end()) s[x + 10000].insert(y);
		}	
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				int a = p[i].first, b = p[i].second;
				int c = p[j].first, d = p[j].second;

				if (bc(a + b - d + 10000, b + c - a) && s[a+b-d+10000].find(b + c - a) != s[a+b-d+10000].end() &&
					bc(c + b - d + 10000, d + c - a) && s[c+b-d+10000].find(d + c - a) != s[c+b-d+10000].end())
				{
					int m = (a - c)*(a - c) + (b - d)*(b - d);
					if (sol < m) sol = m;
				}
				if (bc(a - b + d + 10000, b - c + a) && s[a-b+d+10000].find(b - c + a) != s[a-b+d+10000].end() &&
					bc(c - b + d + 10000, d - c + a) && s[c-b+d+10000].find(d - c + a) != s[c-b+d+10000].end())
				{
					int m = (a - c)*(a - c) + (b - d)*(b - d);
					if (sol < m) sol = m;
				}
			}
		printf("%d\n", sol);
	}
	return 0;
}