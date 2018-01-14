#include <cstdio>

bool n[300000]={1,1,0};

int main()
{
	for(int i=2;i<300000;i++)
		if(!n[i])
			for(int j=2;i*j<300000;j++) n[i*j]=true;
	while(1)
	{
		int x,check=0;
		scanf("%d",&x);
		if(!x) return 0;
		for(int i=x+1;i<=2*x;i++)
			if(!n[i]) ++check;
		printf("%d\n",check);
	}
	return 0;
}