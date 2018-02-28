#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

ll n, m, k, sol = 0, tmp = 0;
bool d[2001][2001];
ll c[2001] = { 0 };
ll num[2001] = { 0 };

int main()
{
 cin >> n >> m >> k;
 for (int i = 0; i < n; i++)
 {
  char s[2010];
  scanf("%s", s);
  for (int j = 0; j < m; j++)
  {
   if (s[j] == '*') d[i][j] = 0;
   else d[i][j] = 1, tmp++;
  }
 }
 if (k == 1)
 {
  cout << tmp;
  return 0;
 }
 for (int i = 0; i < n; i++)
 {
  ll conti = 0;
  for (int j = 0; j < m; j++)
  {
   if (d[i][j]) conti++;
   else
   {
    c[conti]++;
    conti = 0;
   }
  }
  c[conti]++;
 }
 for (int j = 0; j < m; j++)
 {
  ll conti = 0;
  for (int i = 0; i < n; i++)
  {
   if (d[i][j]) conti++;
   else
   {
    c[conti]++;
    conti = 0;
   }
  }
  c[conti]++;
 }
 for (int i = 1; i < 2001; i++)
  if (i >= k) num[i] = i - k + 1;
 for (int i = 1; i < 2001; i++) sol += c[i] * num[i];
 cout << sol;
 return 0;
}