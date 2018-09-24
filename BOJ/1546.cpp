#include <stdio.h>

int main()
{
    int n;
    double max=0,sum=0;
    scanf("%d",&n);
    double* a=new double[n];
    for(int i=0;i<n;i++) scanf("%lf",a+i);
    for(int i=0;i<n;i++)
        if(max<a[i]) max=a[i];
    for(int i=0;i<n;i++) a[i]=a[i]/max*100.0;
    for(int i=0;i<n;i++) sum+=a[i];
    printf("%.2lf",sum/(double)n);
    return 0;
}