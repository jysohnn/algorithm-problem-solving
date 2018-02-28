#include <iostream>

using namespace std;

int n, k;
int mmin, mmax;

int main()
{
 cin >> n >> k;
 if (k == 0 || n == k) cout << 0 << ' ' << 0;
 else
 {
  if (n / 3 >= k) cout << 1 << ' ' << 2 * k;
  else cout << 1 <<' '<< n - k;
 }
 return 0;
}