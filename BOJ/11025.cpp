#include <cstdio>

using namespace std;

int n, m;

int jo(int n, int k)
{
	int ret = 1;
	for (int i = 2; i <= n; i++) ret = (ret + k - 1) % i + 1;
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	printf("%d", jo(n, m));
	return 0;
}