#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 2000000001;
int n;
int a[2002];
int d[2002][2002];
int sol = INF;

int abs(int x, int y)
{
    int ret;
    if(x == 0 || y == 0) return 0;
    ret = a[x] - a[y];
    if(ret < 0) return -1 * ret;
    else return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) d[i][j] = INF;
    d[1][0] = 0;
    d[0][1] = 0;
    d[1][2] = 0;
    d[2][1] = 0;
    for(int i=2;i<=n;i++)
    {
        d[i][0] = d[i-1][0] + abs(i,i-1);
        d[0][i] = d[0][i-1] + abs(i,i-1);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i < j)
            {
                d[i][j+1] = min(d[i][j+1], d[i][j] + abs(j+1,j));
                d[j+1][j] = min(d[j+1][j], d[i][j] + abs(j+1,i));
            }
            else if(i > j)
            {
                d[i+1][j] = min(d[i+1][j], d[i][j] + abs(i+1,i));
                d[i][i+1] = min(d[i][i+1], d[i][j] + abs(i+1,j));
            }
        }
    for(int i=0;i<n;i++)
        if(sol > d[i][n]) sol = d[i][n];
    printf("%d",sol);
    return 0;
}