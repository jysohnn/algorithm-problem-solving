#include <cstdio>
#include <cstring>

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int t;
int m,n,k;
int map[51][51];
bool v[51][51];

bool bc(int x, int y)
{
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    else return false;
}

void dfs(int x, int y)
{
    v[x][y] = 1;
    for(int i=0;i<4;i++)
        if(bc(x+dx[i],y+dy[i]) && map[x+dx[i]][y+dy[i]] && !v[x+dx[i]][y+dy[i]])
            dfs(x+dx[i],y+dy[i]);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int sol = 0;
        memset(map,0,sizeof(map));
        memset(v,0,sizeof(v));
        scanf("%d %d %d",&m,&n,&k);
        for(int i=0;i<k;i++)
        {
            int x, y;
            scanf("%d %d",&x,&y);
            map[x][y] = 1;
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!v[i][j] && map[i][j]) dfs(i,j), sol++;
        printf("%d\n",sol);
    }
    return 0;
}