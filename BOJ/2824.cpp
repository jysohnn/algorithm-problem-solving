#include <cstdio>
#include <vector>

using namespace std;

vector<long long> v;
int n, m;
long long a[1001], b[1001];
long long sol = 1;
bool overflow = false;
const long long LIM = 1000000000;

long long gcd(long long x, long long y)
{
	if (x % y == 0) return y;
	else return gcd(y, x%y);
}

int numLen(long long sol)
{
	int c;
	for (c = 0; sol; c++) sol /= 10;
	return c;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", b + i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int g = gcd(a[i], b[j]);
			if (g != 1) a[i] /= g, b[j] /= g, v.push_back(g);
		}
	for (int i = 0; i < v.size(); i++)
	{
		if (sol >= LIM / v[i])
		{
			overflow = true;
			sol = ((sol % LIM) * (v[i] % LIM)) % LIM;
		}
		else sol *= v[i];
	}
	if (overflow)
		for (int i = 0; i < 9 - numLen(sol); i++) putchar('0');
	printf("%lld", sol);
	return 0;
}