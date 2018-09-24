#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m, sol = 0;
vector<ll> adj[1001];
bool v[1001] = {0};

void dfs(ll x)
{
    v[x] = 1;
    for(ll i=0; i<adj[x].size(); i++)
        if(!v[adj[x][i]]) dfs(adj[x][i]);
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<m; i++)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y); x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i=0; i<n; i++)
        if(!v[i]) dfs(i), sol++;
    printf("%lld", sol);
    return 0;
}