#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int i,j;
    int n=8;
    
    int* a=(int*)malloc(sizeof(int)*n);
    int* b=(int*)malloc(sizeof(int)*n);
    
    for(i=0;i<n;i++) scanf("%d",a+i);
    for(i=0;i<n;i++) b[i]=a[i];
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }   
        }
    }
    
    int sum=0;
    for(i=3;i<n;i++) sum = sum+a[i];
    printf("%d\n",sum);
    
    for(i=0;i<n;i++)
    {
    	int count=0;
    	for(j=3;j<n;j++)
    	{
    		if(b[i]==a[j])
			{
			  count++;
			  printf("%d",i+1);
			  if(count!=5) printf(" ");
		    }
		}
	}
	
    free(a);
    free(b);
    return 0;
}