#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int f[2002][2002] = {0};
bool v[2002];
int p[2002];
int sol = 0;

bool dfs(int s)
{
    v[s] = 1;
    if(s == n+m+1) return true;

    for(int i=1;i<=n+m+1;i++)
        if(f[s][i] && !v[i])
        {
            p[i] = s;
            if(dfs(i)) return true;
        }
    return false;
}

void update(int e)
{
    if(e == 0) return;
    f[p[e]][e]--;
    f[e][p[e]]++;
    update(p[e]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int nn;
        scanf("%d",&nn);
        for(int j=0;j<nn;j++)
        {
            int x;
            scanf("%d",&x);
            f[i][x+n] = 1;
        }
    }
    for(int i=1;i<=n;i++) f[0][i] = 1;
    for(int i=n+1;i<=n+m;i++) f[i][n+m+1] = 1;
    for(int i=0;i<2002;i++)
    {
        fill(v, v+2002, 0);
        if(dfs(0)) update(n+m+1);
        else break;
        sol++;
    }
    printf("%d",sol);
    return 0;
}