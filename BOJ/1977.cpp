#include <cstdio>

bool x[10001]={0};

int main()
{
	for(int i=1;i<=100;i++) x[i*i]=true;
	int m,n,sum=0;
	scanf("%d %d",&m,&n);
	for(int i=m;i<=n;i++)
		if(x[i]) sum+=i;
	if(!sum){printf("-1"); return 0;}
	printf("%d\n",sum);
	for(int i=m;i<=n;i++)
		if(x[i]) {printf("%d",i); break;}
	return 0;
}