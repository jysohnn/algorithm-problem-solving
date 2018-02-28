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

set<char> s = { 'a', 'e', 'i', 'o', 'u', 'y' };
string str;

int main()
{
 ll n;
 cin >> n >> str;
 while (1)
 {
  bool check = 1;
  for (auto i = str.begin();i < --str.end() ;i++)
  {
   if (s.find(*i) != s.end() && s.find(*(i+1)) != s.end())
   {
    str.erase(i + 1);
    check = 0;
    break;
   }
  }
  if (check) break;
 }
 cout << str;
 return 0;
}