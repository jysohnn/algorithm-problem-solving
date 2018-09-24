#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int n, m;
map<int, int> s;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d",&x);
		if(s.find(x) != s.end()) s[x] = s[x] + 1;
		else s[x] = 1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x; scanf("%d", &x);
		if (s.find(x) != s.end()) printf("%d ",s[x]);
		else printf("0 ");
	}
	return 0;
}