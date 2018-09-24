#include <stdio.h>

typedef struct
{
    char name[16];
    int day;
} man;

int main()
{
    int n,i,j;
    man a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int d,m,y;
        scanf("%s %d %d %d",a[i].name,&d,&m,&y);
        a[i].day=d+m*100+y*10000;
    }
    for(i=n-1;i>0;i--)
        for(j=0;j<i;j++)
            if(a[j].day>a[j+1].day)
            {
                man tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
    printf("%s\n%s",a[n-1].name,a[0].name);
    return 0;
}