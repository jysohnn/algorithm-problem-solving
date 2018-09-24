#include <stdio.h>
int main()
{
	int i,j,check=1,x,y,sum=0;
	int a[1001]={0};
	for(i=1;1;i++)
	{
	 for(j=0;j<i;j++,check++)
	 {
	 	a[check]=i;
	 	if(check==1000) break;
	 }
	 if(check==1000) break;
    }
    scanf("%d %d",&x,&y);
    for(i=x;i<=y;i++) sum=sum+a[i];
    printf("%d\n",sum);
}