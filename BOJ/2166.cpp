#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> ll;

ll a[10001];
int n;

double area()
{
	double sol = 0;
	for (int i = 1;i < n - 1;i++)
		sol += (a[i].first - a[0].first)*(a[i + 1].second - a[0].second)
		- (a[i + 1].first - a[0].first)*(a[i].second - a[0].second);
	return (double)sol/2.0 > 0.0 ? (double)sol / 2.0 : (double)sol / -2.0;
}

int main()
{
	long long sol = 0;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		long long x, y;
		scanf("%lld %lld", &x, &y);
		a[i].first = x;
		a[i].second = y;
	}
	printf("%.1lf", area());
	return 0;
}