#include <cstdio>

int n;

int main()
{
    scanf("%d",&n);
    if(n == 1) {printf("*"); return 0;}
    for(int i=0;i<n*2;i++)
    {
        if(n % 2 == 1)
        {
            if(i % 2 == 0) for(int j=0;j<n/2+1;j++) printf("* ");
            else for(int j=0;j<n/2;j++) printf(" *");
            putchar('\n');
        }
        else
        {
            if(i % 2 == 0) for(int j=0;j<n/2;j++) printf("* ");
            else for(int j=0;j<n/2;j++) printf(" *");
            putchar('\n');
        }
    }
    return 0;
}