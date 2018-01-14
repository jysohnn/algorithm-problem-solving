#include <cstdio>

int a[42] = {0};
int sol = 0;

int main()
{
	for(int i=0;i<10;i++)
	{
		int x;
		scanf("%d",&x);
		a[x%42]++;
	}
	for(int i=0;i<42;i++)
		if(a[i]) sol++;
	printf("%d",sol);
	return 0;
}