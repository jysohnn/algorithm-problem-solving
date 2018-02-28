#include <iostream>

using namespace std;

int n;

int gcd(int a, int b)
{
 int c;
 while (a != 0) {
  c = a; a = b%a;  b = c;
 }
 return b;
}

int main()
{
 int i = 0;
 cin >> n;
 if (n % 2 == 0) i = -1;
 for (i += n / 2; i > 0; i--)
  if (gcd(i, n - i) == 1) break;
 cout << i << ' ' << n - i;
 return 0;
}