#include <stdio.h>
int main()
{
    int k,i,j,l;
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        int n,a[50],maxgap=0;
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d",a+j);
        for(j=n-1;j>0;j--)
            for(l=0;l<j;l++)
                if(a[l]<a[l+1])
                {
                    int tmp=a[l];
                    a[l]=a[l+1];
                    a[l+1]=tmp;
                }
        for(j=0;j<n-1;j++)
            if(maxgap<a[j]-a[j+1]) maxgap=a[j]-a[j+1];
        printf("Class %d\n",i);
        printf("Max %d, Min %d, Largest gap %d\n",a[0],a[n-1],maxgap);
    }
    return 0;
}