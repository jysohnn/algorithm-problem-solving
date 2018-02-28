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

ll n;
ll a[5001];

int main()
{
 cin >> n;
 for (int i = 0; i < n; i++)
 {
  scanf("%lld", a+i);
  a[i]--;
 }
 bool flag = 0;
 for (int i = 0; i < n; i++)
  if (i == a[a[a[i]]]) flag = 1;
 if (flag) cout << "YES";
 else cout << "NO";
 return 0;
}