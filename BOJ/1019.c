#include <stdio.h>
int LengthOfNumber(int x)
{
    int i;
    for(i=0;x;i++) x=x/10;
    return i;
}
int FrontOfPivot(int x,int idx)
{
    int i;
    for(i=0;i<idx;i++) x /= 10;
    return x;
}
int BackOfPivot(int x,int idx)
{
    int i,tmp=1;
    for(i=0;i<idx-1;i++) tmp *= 10;
    return x%tmp;
}
void Page_check(int* n, int x)
{
    int i, j, times = 1;
    int len = LengthOfNumber(x);
    int num = x;

    for(i=1;i<len;i++) times *= 10;

    for(i=len;i>0;i--)
    {
        int pivot = num / times;
        for(j=0;j<10;j++) n[j] += FrontOfPivot(x,i) * times;
        if(pivot == 0) n[0] -= times;
        n[pivot] += (BackOfPivot(x,i) + 1);
        for(j=1;j<pivot;j++) n[j] += times;

        num = num % times;
        times /= 10;
    }
}
int main()
{
    int x, i;
    int n[10] = {0};
    scanf("%d",&x);
    Page_check(n, x);
    for(i=0;i<10;i++) printf("%d ",n[i]);
    return 0;
}