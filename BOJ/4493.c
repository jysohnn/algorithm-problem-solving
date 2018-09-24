#include <stdio.h>
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,a=0,b=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			char x,y;
			getchar();
			scanf("%c %c",&x,&y);
			if(x=='R'&&y=='S') a++;
			else if(x=='S'&&y=='R') b++;
			else if(x=='P'&&y=='R') a++;
		    else if(x=='R'&&y=='P') b++;
			else if(x=='P'&&y=='S') b++;
			else if(x=='S'&&y=='P') a++;
		}
		if(a>b) printf("Player 1\n");
		else if(a<b) printf("Player 2\n");
		else printf("TIE\n");
	}
	return 0;
}