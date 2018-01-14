#include <cstdio>
int main()
{
    int a[9];
    int sol=-100;
    for(int i=0;i<9;i++) scanf("%d",a+i);
    for(int i=0;i<9;i++) sol+=a[i];

    for(int i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
            if(a[i]+a[j] == sol)
            {
                for(int k=0;k<9;k++)
                    if(k!=i && k!=j) printf("%d\n",a[k]);
                break;
            }
    return 0;
}