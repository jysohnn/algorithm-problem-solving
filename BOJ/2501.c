#include <stdio.h>
int main()
{
	int n,k,i,check=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
    	if(n%i==0)
    	{
    		check++;
		}
		if(k==check) {printf("%d\n",i); break;}
	}
	if(i==n+1) printf("0\n");
	return 0;
}