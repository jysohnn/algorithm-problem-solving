#include <cstdio>
#include <vector>
#include <queue>
#define INF 999999999

using namespace std;

typedef pair<int,int> pii;

int n,m,s;
vector<pii> adj[20001];
priority_queue<pii,vector<pii>,greater<pii> > q;
bool visit[20001];
int dis[20001];

void dijk()
{
    int cur;
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
    scanf("%d %d %d",&n,&m,&s);
    s--;
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        adj[x-1].push_back(make_pair(y-1,w));
    }
    for(int i=0;i<20001;i++) dis[i] = INF;
    dijk();
    for(int i=0;i<n;i++)
    {
        if(dis[i] == INF) printf("INF\n");
        else printf("%d\n",dis[i]);
    }
    return 0;
}