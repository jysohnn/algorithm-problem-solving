#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int k, n, x[500001];
map<int, int> m;

int main()
{
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) scanf("%d", x + i);
	for (int i = 0; i < n; i++)
	{
		auto tmp = m.find(x[i]);
		if (tmp == m.end()) m.insert(make_pair(x[i], 1));
		else
		{
			int count = m[x[i]]; count++;
			m.erase(tmp);
			m.insert(make_pair(x[i], count));
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (m[x[i]] == 1)
		{
			printf("%08d\n",x[i]);
			k--;
			if (k == 0) break;
		}
		else
		{
			int count = m[x[i]]; count--;
			m.erase(x[i]);
			m.insert(make_pair(x[i], count));
		}
	}
	return 0;
}