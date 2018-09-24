#include <cstdio>

int a[101] = {0};
int t;
int n;

int main()
{
	for(int i=1;i<=10;i++)
		for(int j=i*i;j<101;j++) a[j]++;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}