#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
pll a[3];

ull solve(pll x, pll y)
{
 return (ull)(x.first - y.first)*(x.first - y.first) +
  (ull)(x.second - y.second)*(x.second - y.second);
}

int main()
{

 for (int i = 0; i < 3; i++) cin >> a[i].first >> a[i].second;
 ull q = solve(a[0], a[1]);
 ull w = solve(a[1], a[2]);
 if (q == w)
 {
  if (2 * a[1].first == (a[0].first + a[2].first) && 
   2 * a[1].second == (a[0].second + a[2].second)) printf("No");
  else printf("Yes");
 }
 else printf("No");
 return 0;
}