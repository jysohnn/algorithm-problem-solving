#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999

using namespace std;

typedef pair<int,int> pii;

int n,m;
int a,b;
vector<pii> adj[801];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool visit[801];
long long dis[801];
long long sol1 = 0, sol2 = 0;

void dijk(int s)
{
    int cur;
    for(int i=0;i<801;i++) visit[i] = 0,dis[i] = INF;
    dis[s] = 0;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        while(!q.empty() && visit[q.top().second]) q.pop();
        if(q.empty()) break;
        cur = q.top().second;
        q.pop();
        visit[cur] = 1;
        for(int i=0;i<adj[cur].size();i++)
            if(dis[adj[cur][i].first] > dis[cur]+adj[cur][i].second)
            {
                dis[adj[cur][i].first] = dis[cur]+adj[cur][i].second;
                q.push(make_pair(dis[adj[cur][i].first],adj[cur][i].first));
            }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        adj[x-1].push_back(make_pair(y-1,w));
        adj[y-1].push_back(make_pair(x-1,w));
    }
    scanf("%d %d",&a,&b);
    a--;b--;
    dijk(a);
    sol1 += (dis[b]+dis[0]), sol2 += dis[n-1];
    dijk(b);
    sol1 += dis[n-1], sol2 += (dis[a]+dis[0]);
    sol1 = min(sol1,sol2);
    if(sol1 >= INF) printf("-1");
    else printf("%lld",sol1);
    return 0;
}