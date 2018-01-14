#include <cstdio>

int d[10001] = { 0 };
int t;

int main()
{
	int n;
	int cost = 0;
	scanf("%d",&t);
	
	for (int i = 0; i < 10001; i++)
	{
		while (cost * (cost + 1) < i) cost++;
		if (cost * (cost + 1) > i) cost--;
		d[i] = cost;
	}

	while (t--) 
	{
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}