#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct aa
{
	ll a;
	ll b;
	ll c;
	ll idx;
};

ll n;
aa q[4];

bool cmp(aa& x, aa& y)
{
	if (x.a > y.a) return 1;
	else if (x.a < y.a) return 0;
	else
	{
		if (x.b < y.b) return 1;
		else if (x.b > y.b) return 0;
		else return x.c < x.c;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld %lld %lld", &q[i].a, &q[i].b, &q[i].c), q[i].idx = i;
	sort(q, q + n, cmp);
	cout << q[0].idx + 1;
	return 0;
}