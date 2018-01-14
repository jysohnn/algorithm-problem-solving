#include <cstdio>

int a[1001][1001] = {0};

int main()
{
	int x = 1001;
	int n,k;
	for(int i=0;i<x;i++) a[i][0] = 1, a[i][i] = 1;
	for(int i=1;i<x;i++)
		for(int j=1;j<i;j++) a[i][j] = (a[i-1][j-1] + a[i-1][j]) % 10007;
	scanf("%d %d",&n,&k);
	printf("%d",a[n][k]);
	return 0;
}