#include <cstdio>

int a[1001];
int d[1001] = { 0 };
int n, sol = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 1; i < n; i++)
		if (a[i - 1] < a[i]) d[i] = a[i] - a[i - 1] + d[i - 1];
	for (int i = 0; i < n; i++)
		if (sol < d[i]) sol = d[i];
	printf("%d",sol);
	return 0;
}