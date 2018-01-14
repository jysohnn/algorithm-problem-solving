#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		char x[100001], y[100001];
		int n, b = 0, w = 0;
		scanf("%d %s %s",&n,x,y);
		for (int i = 0; i < n;i++)
			if (x[i] != y[i])
			{
				if (y[i] == 'B') b++;
				else w++;
			}
		int tmp = min(b, w);
		b -= tmp, w -= tmp;
		printf("%d\n", tmp + b + w);
	}
	return 0;
}