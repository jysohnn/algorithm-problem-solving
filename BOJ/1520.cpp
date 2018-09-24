#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m;
ll a[501][501];
ll dp[501][501];
const ll dx[4] = {1, -1, 0, 0};
const ll dy[4] = {0, 0, 1, -1};

bool bc(ll x, ll y) {return x >= 0 && x < n && y >= 0 && y < m;}

ll solve(ll x, ll y)
{
    ll ret = 0;
    if(dp[x][y] != -1) return dp[x][y];
    if(x == 0 && y == 0) return dp[x][y] = 1;
    for(ll i=0; i<4; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(bc(nx, ny) && a[nx][ny] > a[x][y]) ret += solve(nx, ny);
    }
    return dp[x][y] = ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<n; i++)
        for(ll j=0; j<m; j++) scanf("%lld", &a[i][j]);
    printf("%lld", solve(n-1, m-1));
    return 0;
}