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

ll n, s, f;
ll a[200002] = { 0 };
ll dp[200002] = { 0 };
vector<ll> sol;

int main()
{
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  ll x;
  scanf("%lld", &x);
  a[i] = x, a[i + n] = x;
 }
 cin >> s >> f;
 dp[0] = a[0];
 for (int i = 1; i < 2 * n; i++) dp[i] = dp[i - 1] + a[i];
 ll term = f - s;
 ll m = dp[term - 1], from = 1;
 for (int i = 0; i < n; i++)
 {
  ll p = dp[i + term] - dp[i];
  if (p > m)
  {
   sol.clear();
   m = p;
   from = i + 2;
   if (from > s) sol.push_back(s + n - from + 1);
   else if (s > from) sol.push_back(s - from + 1);
   else sol.push_back(1);
  }
  else if (p == m)
  {
   from = i + 2;
   if (from > s) sol.push_back(s + n - from + 1);
   else if (s > from) sol.push_back(s - from + 1);
   else sol.push_back(1);
  }
 }
 cout << *min_element(sol.begin(), sol.end());
 return 0;
}