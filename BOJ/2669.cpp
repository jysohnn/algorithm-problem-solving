#include <cstdio>

bool e[101][101] = {0};
int sol = 0;

int main()
{
	for(int i=0;i<4;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for(int i=a+1;i<=c;i++)
			for(int j=b+1;j<=d;j++) e[i][j] = 1;
	}
	for(int i=1;i<101;i++)
		for(int j=1;j<101;j++)
			if(e[i][j]) sol++;
	printf("%d",sol);
	return 0;
}