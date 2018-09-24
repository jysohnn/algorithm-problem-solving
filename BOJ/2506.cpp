#include <cstdio>

int sol = 0;

int main()
{
	int n, count = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x) count++;
		else count = 0;
		sol += count;
	}
	printf("%d",sol);
	return 0;	
}