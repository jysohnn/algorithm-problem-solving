#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
double k, c1, c2, a, b, n;
double dx, sol = 0.0;

int main()
{
	cin >> k >> c1 >> c2 >> a >> b >> n;
	dx = (b - a) / n;
	double e = c1 * (b*b - a*a) / 2 - c2 * (b - a);
	e = (e / dx) - (c1 * dx * n * (n - 1) / 2);
	e /= n;
	e -= (c2 + c1 * a);
	e /= c1;
	if (0.0 <= e && e <= dx) printf("%.8lf", e);
	else printf("-1");
	return 0;
}