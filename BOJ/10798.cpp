#include <cstdio>

char a[5][16] = {0};

int main()
{
    for(int i=0;i<5;i++) scanf("%s",a[i]);
    for(int j=0;j<15;j++)
        for(int i=0;i<5;i++)
            if(a[i][j]) printf("%c",a[i][j]);
    return 0;
}