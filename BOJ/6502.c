#include <stdio.h>
int main()
{
	int i;
	for(i=1;1;i++)
	{
		int r,w,l;
		scanf("%d",&r);
		if(r==0) break;
		scanf("%d %d",&w,&l);
		r=2*2*r*r;
		w=w*w+l*l;
		if(r<w) printf("Pizza %d does not fit on the table.\n",i);
		else printf("Pizza %d fits on the table.\n",i);
	}
	return 0;
}