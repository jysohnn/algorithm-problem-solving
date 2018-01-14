#include <cstdio>
#include <algorithm>

using namespace std;

pair<double, double> x[50001];
pair<double, double> sol;
int n;
double t;
long long a[50001];
long long v[50001];

pair<double, double> join(pair<double, double> z, pair<double, double> y)
{
	pair<double, double> ret;
	if (z.second > y.second)
	{
		ret.second = y.second;
		if (z.first > y.second) return pair<double, double>(-1.0, -1.0);
	}
	else
	{
		ret.second = z.second;
		if (y.first > z.second) return pair<double, double>(-1.0, -1.0);
	}
	ret.first = max(z.first, y.first);
	return ret;
}

int check()
{
	for (int i = 1; i < n; i++)
	{
		pair<double, double> tmp = join(x[i], x[i - 1]);
		sol = join(tmp, sol);
		if (sol.first < 0.0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d %lf", &n, &t);
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	for (int i = 0; i < n; i++) scanf("%lld", v + i);
	for (int i = 0; i < n; i++)
	{
		x[i].first = (double)a[i] - (double)v[i] * t;
		x[i].second = (double)a[i] + (double)v[i] * t;
		if (x[i].first < 1.0) x[i].first = 1.0;
		if (x[i].second > 1000000000.0) x[i].second = 1000000000.0;
	}
	sol = x[0];
	printf("%d", check());
	return 0;
}