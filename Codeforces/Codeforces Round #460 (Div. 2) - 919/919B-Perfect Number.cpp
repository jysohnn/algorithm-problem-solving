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

ll k;
ll sol[10001];

bool check(ll x)
{
 ll s = 0;
 while (x) s += (x % 10), x /= 10;
 if (s == 10) return 1;
 else return 0;
}

int main()
{
 ll i = 0, x = 1;
 while (i < 10000)
 {
  i += 1;
  while (!check(x)) x++;
  sol[i] = x; x++;
 }
 cin >> k;
 cout << sol[k];
 return 0;
}