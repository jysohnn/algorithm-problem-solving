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

ll n, k;
ll a[100001];
ll x, y, m = 1000000000000000001;

int main()
{
 cin >> n >> k;
 for (int i = 1; i <= k; i++) scanf("%lld", a + i);
 for (int i = 1; i <= k; i++)
 {
  if ((n % a[i]) < m)
  {
   m = n % a[i];
   x = i;
   y = n / a[i];
  }
 }
 cout << x << ' ' << y;
 return 0;
}