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

ll n;
double m, sol = 9999999999.0;

int main()
{
 cin >> n >> m;
 for (int i = 0; i < n; i++)
 {
  double x, y;
  scanf("%lf %lf", &x, &y);
  x /= y;
  if (x < sol) sol = x;
 }
 printf("%.8lf", sol * m);
 return 0;
}