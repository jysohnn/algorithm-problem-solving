#include <stdio.h>
int main()
{
    int n;
    int i,j,k;
    char a[21]={0};
    
    scanf("%d",&n);
    
	for(i=0;i<n;i++)
	{
		int r;
     	scanf("%d ",&r);
     	scanf("%s",a);
     	for(k=0;a[k]!=0;k++)
		{
			for(j=0;j<r;j++) printf("%c",a[k]);
	    }
	    printf("\n");
	}
	
	return 0;
}