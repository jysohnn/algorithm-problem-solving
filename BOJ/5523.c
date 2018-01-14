#include <stdio.h>
int main()
{
	int n,i,a=0,b=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x>y) a++;
		if(x<y) b++;
	}
	printf("%d %d\n",a,b);
	return 0;
}