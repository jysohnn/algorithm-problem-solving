#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int a[5001];
int dp[5001];
bool visit[5001] = {0};
vector<int> adj[5001];

int solve(int x)
{
	if(dp[x] != -1) return dp[x];
	
	int ret = 1;
	for(int i=0;i<adj[x].size();i++)
		if(a[x] < a[adj[x][i]]) ret = max(ret, 1 + solve(adj[x][i]));
	return dp[x] = ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0; i<m; i++)
	{
		int x,y; scanf("%d %d",&x,&y); x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0;i<n;i++) printf("%d\n", solve(i));
	return 0;
}