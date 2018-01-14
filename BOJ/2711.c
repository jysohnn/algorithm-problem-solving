#include <stdio.h>
int main()
{
    int n;
    int i,j,k;
    char a[81]={0};
    
    scanf("%d",&n);
    
	for(i=0;i<n;i++)
	{
		int r;
     	scanf("%d ",&r);
     	scanf("%s",a);
        for(j=0;a[j]!=0;j++)
        {
        	if(j!=r-1) printf("%c",a[j]);
		}
	    printf("\n");
	}
	
	return 0;
}