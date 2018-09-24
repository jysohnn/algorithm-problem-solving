#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m;
	int i,j;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	int* a=(int*)malloc(sizeof(int)*n);
    int* x=(int*)malloc(sizeof(int)*m);
    int* y=(int*)malloc(sizeof(int)*m);
	
	a[0]=1;
	for(i=1;i<n;i++) a[i]=0;
	
	for(i=0;i<m;i++) scanf("%d %d",x+i,y+i);
	
	for(i=0;i<m;i++)
    {
		for(j=0;j<m;j++)
		{
			int o=x[j]-1;
			int p=y[j]-1;
			
			if(a[o]!=a[p])
			{
				if(a[o]==1) a[p]=a[o];
				else a[o]=a[p];
			}
		}
	}
	
	int check=0;
	
	for(i=1;i<n;i++)
	{
		if(a[i]==1) check++;
	}
	
	printf("%d",check);
	
	free(a);
	free(x);
	free(y);
	return 0;
}