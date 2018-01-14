#include <stdio.h>
void sort(int* a,int n)
{
    int i,j;
    for(i=n-1;i>0;i--)
        for(j=0;j<i;j++)
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
};
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int a[10];
        for(i=0;i<10;i++) scanf("%d",a+i);
        sort(a,10);
        printf("%d\n",a[7]);
    }
    return 0;
}