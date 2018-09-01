#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, sol = 0;
ll a[101][101];
bool v[101][101];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool bc(int x, int y) {return x >= 0 && x < n && y >= 0 && y < n;}

void dfs(int x, int y)
{
    v[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(bc(nx, ny) && !v[nx][ny]) dfs(nx, ny);
    }
}

int main()
{
    scanf("%lld", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) scanf("%lld", &a[i][j]);
    for(int k=0; k<101; k++)
    {
        ll c = 0;
        memset(v, 0, sizeof(v));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(a[i][j] <= k) v[i][j] = 1;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(!v[i][j]) dfs(i, j), c++;
        sol = max(sol, c);
    }
    printf("%lld", sol);
    return 0;
}