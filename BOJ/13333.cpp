#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int n, a[1001];
int sol = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n, greater<int>());
	for (int i = 0; i <= n; i++)
	{
		bool flag = 1;
		if (i == 0)
		{
			for (int j = 1; j < n; j++)
				if (i < a[j]) flag = 0;
		}
		else
		{
			if (a[i - 1] < i) flag = 0;
			for (int j = i; j < n; j++)
				if (i < a[j]) flag = 0;
		}
		if (flag) sol = max(sol, i);
	}
	printf("%d", sol);
	return 0;
}