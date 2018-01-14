#include <cstdio>
#include <cstring>

char a[21][21];
bool v[21][21] = {0};
bool vv[26] = {0};
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int m,n;
int max = 0;

bool bc(int x,int y)
{
    if(x >= 0 && x < m && y >= 0 && y < n) return true;
    else return false;
}

void dfs(int x,int y, int l)
{
    if(l > max) max = l;
    for(int i=0;i<4;i++)
        if(bc(x+dx[i],y+dy[i]) && !v[x+dx[i]][y+dy[i]] && !vv[a[x+dx[i]][y+dy[i]] - 'A'])
        {
            v[x+dx[i]][y+dy[i]] = 1;
            vv[a[x+dx[i]][y+dy[i]] - 'A'] = 1;
            dfs(x+dx[i],y+dy[i],l+1);
            v[x+dx[i]][y+dy[i]] = 0;
            vv[a[x+dx[i]][y+dy[i]] - 'A'] = 0;
        }
}

int main()
{
    scanf("%d %d",&m,&n);
    getchar();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++) a[i][j] = getchar();
        getchar();
    }
    v[0][0] = 1;
    vv[a[0][0] - 'A'] = 1;
    dfs(0,0,1);
    printf("%d",max);
    return 0;
}