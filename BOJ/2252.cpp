#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll N = 320002;
ll n, m;
vector<ll> adj[N], sol;
bool v[N] = {0};

void dfs(ll x)
{
    v[x] = 1;
    for(ll i=0; i<adj[x].size(); i++)
        if(!v[adj[x][i]]) dfs(adj[x][i]);
    sol.push_back(x);
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for(ll i=0; i<m; i++)
    {
        ll x, y; scanf("%lld %lld", &x, &y);
        adj[y].push_back(x);
    }
    for(ll i=1; i<=n; i++)
        if(!v[i]) dfs(i);
    for(ll i=0; i<sol.size(); i++) printf("%lld ", sol[i]);
    return 0;
}