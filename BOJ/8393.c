#include <stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	sum=sum+i+1;
	}
	printf("%d\n",sum);
	return 0;
}