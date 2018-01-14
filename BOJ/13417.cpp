#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		int n;
		deque<char> sol;

		scanf("%d", &n); getchar();
		for (int i = 0; i < n; i++)
		{
			char x = getchar();
			getchar();
			if (sol.empty()) sol.push_back(x);
			else if (sol[0] >= x) sol.push_front(x);
			else sol.push_back(x);
		}
		for (int i = 0; i < n; i++) putchar(sol[i]);
		putchar('\n');
	}
	return 0;
}