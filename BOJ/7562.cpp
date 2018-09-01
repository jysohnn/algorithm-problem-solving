#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF = 9999999999;
const ll dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const ll dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll t, n;
ll sx, sy, ex, ey;
ll v[301][301];
ll d[301][301];
ll sol;

bool bc(ll x, ll y) {return x >= 0 && x < n && y >= 0 && y < n;}

void bfs(ll x, ll y)
{
    queue<pll> q;
    q.push({x,y});
    while(!q.empty())
    {
        pll p = q.front(); q.pop();
        if(p.first == ex && p.second == ey) sol = min(sol, d[ex][ey]);
        for(ll k=0; k<8; k++)
        {
            ll nx = p.first + dx[k];
            ll ny = p.second + dy[k];
            if(bc(nx, ny) && !v[nx][ny])
            {
                d[nx][ny] = d[p.first][p.second] + 1;
                v[nx][ny] = 1, q.push({nx, ny});
            }
        }
    }
}

int main()
{
    scanf("%lld", &t);
    while(t--)
    {
        sol = INF;
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        scanf("%lld", &n);
        scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
        bfs(sx, sy);
        printf("%lld\n", sol);
    }
    return 0;
}