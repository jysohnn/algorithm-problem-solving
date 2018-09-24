#include <stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    while(n--)
    {
        int a[5],sum=0;
        for(i=0;i<5;i++) scanf("%d",a+i);
        for(i=4;i>0;i--)
            for(j=0;j<i;j++)
                if(a[j]>a[j+1])
                {
                    int tmp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=tmp;
                }
        sum=a[1]+a[2]+a[3];
        if(a[3]-a[1]>=4) printf("KIN\n");
        else printf("%d\n",sum);
    }
    return 0;
}