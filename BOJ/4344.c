#include <stdio.h>
 
int main()
{
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,count=0;
        double a[1000]={0},sum=0,x;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lf",a+j);
            sum+=a[j];
        }
        sum=sum/(double)n;
        for(j=0;j<n;j++) if(a[j]>sum) count++;
        x=(double)count/(double)n*100.0;
        printf("%.3lf%c\n",x,'%');
    }
    return 0;
}