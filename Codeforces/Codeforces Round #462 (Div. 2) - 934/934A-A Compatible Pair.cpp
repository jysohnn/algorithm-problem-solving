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
const ll INF = 1000000000000000001;
ll a[52], b[52];
ll sol = INF;

int main()
{
 cin >> n >> m;
 for (int i = 0; i < n; i++) scanf("%lld", a + i);
 for (int i = 0; i < m; i++) scanf("%lld", b + i);
 for (int i = 0; i < n; i++)
 {
  ll ysol = -INF;
  for(int j=0;j<m;j++)
   for(int k=0;k<n;k++)
    if (k != i)
    {
     ysol = max(ysol, b[j] * a[k]);
    }
  sol = min(sol, ysol);
 }
 cout << sol;
 return 0;
}