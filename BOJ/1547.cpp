#include <cstdio>

int main()
{
	int m;
	int a[3] = { 1,0,0 };
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		int x, y, tmp;
		scanf("%d %d",&x,&y);
		tmp = a[x - 1];
		a[x - 1] = a[y - 1];
		a[y - 1] = tmp;
	}
	for (int i = 0; i < 3; i++)
		if (a[i]) printf("%d",i+1);
}