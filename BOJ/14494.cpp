#include <cstdio>

bool bc(int x, int y)
{
	if (x > 0 && x < 1001 && y > 0 && y < 1001) return true;
	else return false;
}

long long d[1002][1002] = {0};
int n, m;

int main()
{
	d[1][1] = 1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
		{
			if (bc(i - 1, j)) d[i][j] += d[i - 1][j];
			if (bc(i, j - 1)) d[i][j] += d[i][j - 1];
			if (bc(i - 1, j - 1)) d[i][j] += d[i - 1][j - 1];
			d[i][j] = d[i][j] % 1000000007;
		}
	printf("%lld",d[n][m]);
	return 0;
}