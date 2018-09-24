#include <cstdio>

int main()
{
	int n, sol = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%1d",&x);
		sol += x;
	}
	printf("%d",sol);
	return 0;
}