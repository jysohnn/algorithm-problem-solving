#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;
vector<pii> adj[100001], adj2[100001];
bool visit[100001];
int d[100001];
int n, m;
int s, e;
int sol = 0;

void mst()
{
	priority_queue<piii> q;
	int count = 0;

	q.push(make_tuple(0,s,s));
	while(!q.empty())
	{
		piii x = q.top(); q.pop();
		if(!(get<1>(x) == 0 && get<2>(x) == 0))
		{
			adj2[get<1>(x)].push_back(make_pair(get<2>(x), get<0>(x)));
			adj2[get<2>(x)].push_back(make_pair(get<1>(x), get<0>(x)));
		}
		visit[get<2>(x)] = 1;
		for(int i=0;i<adj[get<2>(x)].size();i++)
			q.push(make_tuple(adj[get<2>(x)][i].second, get<2>(x), adj[get<2>(x)][i].first));
		while(!q.empty() && visit[get<2>(q.top())]) q.pop();
	}
}

void dfs(int x, int y)
{
	visit[x] = 1;
	if(x == e) sol = y;
	for(int i=0;i<adj2[x].size();i++)
		if(!visit[adj2[x][i].first]) dfs(adj2[x][i].first, min(y, adj2[x][i].second));
}

int main()
{
	cin>>n>>m>>s>>e; s--; e--;
	for(int i=0;i<m;i++)
	{
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c); x--; y--;
		adj[x].push_back(make_pair(y,c));
		adj[y].push_back(make_pair(x,c));
	}
	mst();
	memset(visit, 0, sizeof(visit));
	dfs(s, 99999999);
	cout<<sol;
	return 0;
}