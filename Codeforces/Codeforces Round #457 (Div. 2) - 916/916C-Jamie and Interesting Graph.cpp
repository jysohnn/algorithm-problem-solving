#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> tll;
typedef pair<ll, ll> pll;

const ll p = 301381;
ll n, m;
set<pll> s;

int main()
{
 cin >> n >> m; m -= n - 1;
 cout << p << ' ' << p << '\n';

 for (int i = 1; i < n - 1; i++)
 {
  s.insert(pll(i, i + 1));
  printf("%d %d %d\n", i, i+1, 1);
 }
 
 s.insert(pll(n - 1, n));
 printf("%lld %lld %lld\n", n - 1, n, p - n + 2);

 for (int i = 1; i <= n; i++)
  for (int j = i + 1; j <= n; j++)
  {
   if (s.find(pll(i, j)) != s.end()) continue;
   else
   {
    if (m == 0)
    {
     return 0;
    }
    printf("%d %d %d\n", i, j, 99999999);
    m--;
   }
  }
 
 return 0;
}