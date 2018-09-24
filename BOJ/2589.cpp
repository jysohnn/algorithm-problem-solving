#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int,int> > q;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
int n,m;
int a[51][51] = {0};
bool v[51][51];
int sol = 0;

bool bc(int x, int y)
{
    if(x >= 0 && x < n && y >= 0 && y < m) return true;
    else return false;
}

void bfs(int x, int y)
{
    v[x][y] = 1;
    q.push(pair<int,int>(x,y));
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0;i<4;i++)
            if(bc(p.first+dx[i],p.second+dy[i]) && !v[p.first+dx[i]][p.second+dy[i]]
                    && a[p.first+dx[i]][p.second+dy[i]])
            {
                v[p.first+dx[i]][p.second+dy[i]] = 1;
                a[p.first+dx[i]][p.second+dy[i]] = a[p.first][p.second] + 1;
                if(a[p.first+dx[i]][p.second+dy[i]] > sol) sol = a[p.first+dx[i]][p.second+dy[i]];
                q.push(pair<int,int>(p.first+dx[i],p.second+dy[i]));
            }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(getchar() == 'L') a[i][j] = 1;
        getchar();
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j])
            {
                for(int k=0;k<n;k++)
                    for(int l=0;l<m;l++)
                    {
                        v[k][l] = 0;
                        if(a[k][l]) a[k][l] = 1;
                    }
                bfs(i,j);
            }
    if(sol > 0) sol--;
    printf("%d",sol);
    return 0;
}