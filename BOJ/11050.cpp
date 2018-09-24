#include <cstdio>

int a[101][101] = {0};

int main()
{
	int x = 101;
	int n,k;
	for(int i=0;i<x;i++) a[i][0] = 1, a[i][i] = 1;
	for(int i=1;i<x;i++)
		for(int j=1;j<i;j++) a[i][j] = a[i-1][j-1] + a[i-1][j];
	scanf("%d %d",&n,&k);
	printf("%d",a[n][k]);
	return 0;
}