#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll n, l, sol = 0;
ll c[32];
ll w[32];
bool off[32] = { 0 };
vector<ll> v;

int main()
{
 w[0] = 1;
 for (int i = 1; i < 32; i++) w[i] = w[i - 1] * 2;
 cin >> n >> l;
 for (int i = 0; i < n; i++) scanf("%lld", c + i);
 for (int i = 0; i < n; i++)
  for (int j = 1; i + j < n; j++)
  {
   if (pow(2, j) * c[i] < c[i + j]) off[i + j] = 1;
   if (c[i] >= c[i + j]) off[i] = 1;
  }
 for (int i = n - 1; i >= 0; i--)
  if (!off[i])
  {
   if (l >= w[i])
   {
    ll tmp = l / w[i];
    l = l % w[i];
    sol += tmp * c[i];
    if (l == 0) v.push_back(sol);
    else v.push_back(sol + c[i]);
   }
   else v.push_back(sol + c[i]);
  }
 ll s = v[0];
 for (int i = 0; i < v.size(); i++)
  if (v[i] < s) s = v[i];
 cout << s;
 return 0;
}