#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long r, d, n;

double dis(long long x, long long y)
{
 return sqrt(x*x + y*y);
}

int main()
{
 int sol = 0;
 cin >> r >> d >> n;
 for (int i = 0; i < n; i++)
 {
  long long x, y, r2;
  scanf("%I64d %I64d %I64d", &x, &y, &r2);
  if (r - d <= dis(x, y) - r2 && dis(x, y) + r2 <= r) sol++;
 }
 printf("%d",sol);
 return 0;
}