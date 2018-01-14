#include <cstdio>
int n;
int sol = 0;
int main()
{
	scanf("%d",&n);
	for (int i = 2; n - i >= 4; i++)
		if ((n - i) % 2 == 0) sol += ((n - i) / 2 - 1);
	printf("%d", sol);
	return 0;
}