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

ll x = 1, y = 1000000;
ll n, sol = 0;
deque<ll> a;

int main()
{
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  ll x;
  scanf("%lld", &x);
  a.push_back(x);
 }
 while (!a.empty())
 {
  x++; y--; sol++;
  if (!a.empty() && (a[0] == x || a[0] == y)) a.pop_front();
  if (!a.empty() && (a[a.size() - 1] == y || a[a.size() - 1] == x)) a.pop_back();
 }
 cout << sol;
 return 0;
}