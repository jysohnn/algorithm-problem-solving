#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <functional>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;

ll n, m;
ll dis[200002];
vector<pll> adj[200002];
bool visit[200002] = { 0 };

void dijk(int s)
{
 priority_queue<pll, vector<pll>, greater<pll> > q;
 dis[s] = 0;
 q.push(make_pair(0, s));
 while (!q.empty())
 {
  while (!q.empty() && visit[q.top().second]) q.pop();
  if (q.empty()) break;
  int next = q.top().second; q.pop();
  visit[next] = 1;
  for (int i = 0; i < adj[next].size(); i++)
   if (dis[adj[next][i].first] == -1 || dis[adj[next][i].first] > dis[next] + adj[next][i].second)
   {
    dis[adj[next][i].first] = dis[next] + adj[next][i].second;
    q.push(make_pair(dis[adj[next][i].first], adj[next][i].first));
   }
 }
}

int main()
{
 memset(dis, -1, sizeof(dis));
 cin >> n >> m;
 for (int i = 0; i < m; i++)
 {
  ll x, y, cost;
  scanf("%lld %lld %lld",&x, &y, &cost);
  adj[x].push_back(pll(y, 2*cost));
  adj[y].push_back(pll(x, 2*cost));
 }
 for (int i = 1; i <= n; i++)
 {
  ll x; scanf("%lld", &x);
  adj[0].push_back(pll(i, x));
  adj[i].push_back(pll(0, x));
 }
 dijk(0);
 for (int i = 1; i <= n; i++) printf("%lld ", dis[i]);
 return 0;
}