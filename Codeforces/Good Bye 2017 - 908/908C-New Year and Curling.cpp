#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

ll n;
double r;
pdd a[1001];

double sq(double x) { return x*x; }

int main()
{
 cin >> n >> r;
 for (int i = 0; i < n; i++)
 {
  double x;
  scanf("%lf", &x);
  a[i].first = x; a[i].second = r;
 }
 for (int i = 0; i < n; i++)
 {
  for (int j = i - 1; j >= 0; j--)
   if (a[i].first - 2 * r <= a[j].first && a[j].first <= a[i].first + 2 * r
    && a[j].second + sqrt(4.0*sq(r) - sq(a[i].first - a[j].first)) >= a[i].second)
    a[i].second = a[j].second + sqrt(4.0*sq(r) - sq(a[i].first - a[j].first));
 }
 for (int i = 0; i < n; i++) printf("%.11lf ",a[i].second);
 return 0;
}