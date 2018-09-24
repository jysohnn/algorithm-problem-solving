#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int t, n;
set<int> fibo;
vector<int> sol;

int main()
{
	int a=0, b=1, c;
	fibo.insert(0); fibo.insert(1);
	while (1)
	{
		c = a + b;
		if (c > 1000000000) break;
		fibo.insert(c);
		a = b, b = c;
	}

	scanf("%d", &t);
	while (t--)
	{
		sol.clear();
		scanf("%d",&n);
		while (n)
		{
			auto it = fibo.find(n);
			if (it == fibo.end())
			{
				it = fibo.lower_bound(n);
				it--;
			}
			n -= *it; sol.push_back(*it);
		}
		for (auto i = sol.rbegin(); i != sol.rend(); i++) printf("%d ", *i);
		putchar('\n');
	}
	return 0;
}