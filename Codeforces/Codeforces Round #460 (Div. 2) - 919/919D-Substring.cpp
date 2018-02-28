#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

string str;
ll n, m, sol = 0;
int dp[300001][26];
int value[300001];
bool v1[300001] = { 0 };
bool v2[300001];
vector<int> adj[300001];

int* dfs(int x)
{
 v1[x] = 1, v2[x] = 1;
 for (int i = 0; i < adj[x].size(); i++)
 {
  int next = adj[x][i];
  if (v2[next])
  {
   dp[x][0] = -1;
   return dp[x];
  }
  if (v1[next])
  {
   if (dp[next][0] == -1) return dp[next];
   for (int i = 0; i < 26; i++)
    dp[x][i] = max(dp[x][i], dp[next][i]);
  }
  else
  {
   int* tt = dfs(next);
   if (tt[0] == -1) return tt;
   for (int i = 0; i < 26; i++)
    dp[x][i] = max(dp[x][i], tt[i]);
  }
 }
 dp[x][value[x]]++;
 for (int i = 0; i < 26; i++)
  if (dp[x][i] > sol) sol = dp[x][i];
 v2[x] = 0;
 return dp[x];
}

int main()
{
 memset(dp, 0, sizeof(dp));
 cin >> n >> m >> str;
 for (int i = 0; i < n; i++) value[i] = (int)str[i] - 'a';
 for (int i = 0; i < m; i++)
 {
  int x, y;
  scanf("%d %d", &x, &y); x--; y--;
  adj[x].push_back(y);
 }
 int tmp = 0;
 for (int i = 0; i < n; i++)
  if (!v1[i])
  {
   memset(v2, 0, sizeof(v2));
   int* tt = dfs(i);
   if(tt[0] == -1) { cout << -1; return 0; }
   tmp++;
  }
 if (tmp == 0) { cout << -1; return 0; }
 cout << sol;
 return 0;
}