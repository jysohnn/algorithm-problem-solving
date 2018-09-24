#include <cstdio>

int a[16][29][20];

int main()
{
    int x,y,z;
    for(int i=1;i<7981;i++) a[(i-1)%15+1][(i-1)%28+1][(i-1)%19+1] = i;
    scanf("%d %d %d",&x,&y,&z);
    printf("%d",a[x][y][z]);
    return 0;
}