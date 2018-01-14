#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
set<int> s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d",&x);
		s.insert(x);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x; scanf("%d", &x);
		if (s.find(x) != s.end()) printf("1 ");
		else printf("0 ");
	}
	return 0;
}