#include <cstdio>

int main()
{
	for(int i=1;1;i++)
	{
		int x;
		scanf("%d",&x);
		if(x == 0) break;
		if((3*x) % 2 == 1)printf("%d. odd %d\n",i,(x-1)/2);
		else printf("%d. even %d\n",i,x/2);
	}
	return 0;
}