#include <stdio.h>
int main()
{
	int t,i,j;
	int combi[31][31]={0};
	for(i=0;i<31;i++) {combi[i][i]=1;combi[i][0]=1;}
	for(i=2;i<30;i++)
	 for(j=1;j<i;j++) combi[i][j]=combi[i-1][j]+combi[i-1][j-1];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%d\n",combi[m][n]);
	}
	return 0;
}