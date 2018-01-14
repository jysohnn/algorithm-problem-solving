#include <stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	for(j=n-i-1;j>0;j--) printf(" ");
    	printf("*");
    	for(j=0;j<2*i-1;j++) printf(" ");
    	if(i!=0) printf("*");
    	if(i!=n-1) printf("\n");
	}
    return 0;
}