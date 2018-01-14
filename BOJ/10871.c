#include <stdio.h>
int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<m) printf("%d ",x);
	}
	printf("\n");
	return 0;
}