#include <iostream>

using namespace std;

int  n, m;
int a[251][251];
int v[251][251] = {0};
int sol = 0;
const int dx[8] = {1,1,1,-1,-1,-1,0,0};
const int dy[8] = {1,-1,0,1,-1,0,1,-1};

bool bc(int x, int y){ return x >=0 && y >= 0 && x < n && y < m; }
void dfs(int x, int y)
{
    v[x][y] = 1;
    for(int i=0;i<8;i++)
        if(bc(x+dx[i],y+dy[i]) && a[x+dx[i]][y+dy[i]] && !v[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i]);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&(a[i][j]));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!v[i][j] && a[i][j]) sol++, dfs(i,j);
    cout<<sol;
    return 0;
}