#include <cstdio>
int main()
{
	int a[15001];
	int n,m,sol=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(a[i] + a[j] == m) ++sol;
	printf("%d",sol);
	return 0;
}