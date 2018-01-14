#include <iostream>
#include <algorithm>

using namespace std;

int n, sol = 201;
int a[201];
int d[201];

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d", a+i);
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);
	}
	for (int i = 0; i < n; i++) sol = min(sol, n - d[i]);
	printf("%d", sol);
	return 0;
}