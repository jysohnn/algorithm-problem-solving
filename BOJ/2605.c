#include <stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[100];
    for(i=0;i<n;i++) a[i]=i+1;
    for(i=0;i<n;i++)
    {
        int x,tmp=a[i];
        scanf("%d",&x);
        for(j=i;j>=i-x+1;j--) a[j]=a[j-1];
        a[i-x]=tmp;
    }
    for(i=0;i<n;i++)
    {
        if(i!=n-1) printf("%d ",a[i]);
        else printf("%d",a[i]);
    }
    return 0;
}