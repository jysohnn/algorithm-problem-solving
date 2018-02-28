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

ll t;

int main()
{
 cin >> t;
 while (t--)
 {
  bool flag = 0;
  ll x; scanf("%lld", &x);
  if (x == 1)
  {
   printf("-1\n");
   continue;
  }
  if (x == 0)
  {
   printf("1 1\n");
   continue;
  }
  ll s = (ll)sqrt(x), e = (ll)sqrt(2 * x);
  for (ll i = s + 1; i <= e; i++)
  {
   ll test = i*i - x, sq = (ll)sqrt(test);
   if (test == sq * sq && (i / sq) > (i % sq))
   {
    printf("%lld %lld\n", i, i / sq);
    flag = 1; break;
   }
  }
  if (!flag) printf("-1\n");
 }
 return 0;
}