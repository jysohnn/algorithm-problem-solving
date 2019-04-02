#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;

using namespace std;

ll n, m;
ll msol = -1;
bool v[10002];
vector<ll> adj[10002];
vector<ll> sol;

ll solve(ll x)
{
    ll ret = 1;
    v[x] = 1;
    for(int i=0; i<adj[x].size(); i++)
        if(!v[adj[x][i]]) ret += solve(adj[x][i]);
    return ret;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for(int i=0; i<m; i++)
    {
        ll x, y; scanf("%lld %lld", &x, &y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        memset(v, 0, sizeof(v));
        ll tmp = solve(i);
        if(tmp > msol)
        {
            sol.clear();
            msol = tmp;
            sol.push_back(i);
        }
        else if(tmp == msol) sol.push_back(i);
    }
    sort(sol.begin(), sol.end());
    for(int i=0; i<sol.size(); i++) printf("%lld ", sol[i]);
    return 0;
}