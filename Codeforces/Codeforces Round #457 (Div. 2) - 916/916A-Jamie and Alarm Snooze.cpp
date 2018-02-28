#include <iostream>

using namespace std;

using ll = long long;

ll x, h, m, sol = 0;

int main()
{
 cin >> x >> h >> m;
 while (1)
 {
  if (h % 10 == 7 || m % 10 == 7) break;
  m -= x;
  if (m < 0) m += 60, h -= 1;
  if (h < 0) h += 24;
  sol++;
 }
 cout << sol;
 return 0;
}