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

ll k;

int main()
{
 cin >> k;
 if (k > 36)
 {
  cout << "-1";
  return 0;
 }
 else
 {
  int d = k / 2;
  int r = k % 2;
  for (int i = 0; i < d; i++) printf("8");
  for (int i = 0; i < r; i++) printf("6");
 }
 return 0;
}