#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll n, m;

int main()
{
 cin >> n >> m;
 if (n >= 27) { cout << m; return 0; }
 else
 {
  ll x = 1;
  for (int i = 0; i < n; i++) x *= 2;
  cout << m % x;
 }
 return 0;
}