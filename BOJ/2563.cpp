#include <cstdio>

bool a[100][100] = {0};
int sol = 0;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		for(int i=x-1;i<x+9;i++)
			for(int j=y-1;j<y+9;j++) a[i][j] = 1;
	}
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			if(a[i][j]) sol++;
	printf("%d",sol);
	return 0;	
}