#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool leaf[1001] = { 0 };
ll n;
vector<ll> adj[1001];

bool solve(ll r)
{
 bool ret = 1;
 ll count = 0;
 for (int i = 0; i < adj[r].size(); i++)
 {
  if (!leaf[adj[r][i]]) count++;
  else ret = (ret && solve(adj[r][i]));
 }
 if (count < 3) return 0;
 return ret;
}

int main()
{
 cin >> n;
 for (int i = 1; i < n; i++)
 {
  ll x;
  scanf("%lld", &x); x--;
  leaf[x] = 1;
  adj[x].push_back(i);
 }
 if (solve(0)) cout << "Yes";
 else cout << "No";
 return 0;
}