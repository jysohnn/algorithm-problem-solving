#include <cstdio>
#include <vector>

using namespace std;

int n;
double sol = 0.0;
vector<int> adj[100001];
bool visit[100001] = { 0 };

void dfs(int x, int num, double p)
{
 visit[x] = 1;
 int count = 0;
 bool check = 0;
 for (int i = 0; i < adj[x].size(); i++)
  if (!visit[adj[x][i]]) count++;
 for (int i = 0; i < adj[x].size(); i++)
  if (!visit[adj[x][i]]) 
   dfs(adj[x][i], num + 1, p / (double)count), check = 1;
 if (!check) sol += (double)num * p;
 visit[x] = 0;
}

int main()
{
 scanf("%d",&n);
 for (int i = 0; i < n-1; i++)
 {
  int x, y;
  scanf("%d %d",&x,&y);
  adj[x].push_back(y);
  adj[y].push_back(x);
 }
 dfs(1,0,1.0);
 printf("%.15lf",sol);
 return 0;
}