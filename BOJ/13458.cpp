#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, sol = 0;
ll a[1000001];
ll b, c;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	cin >> b >> c;

	for (int i = 0; i < n; i++)
		a[i] = max((ll)0, a[i] - b), sol++;
	for (int i = 0; i < n; i++)
		if (a[i] != 0)
		{
			sol += a[i] / c;
			if (a[i] % c != 0) sol++;
		}

	cout << sol;
	return 0;
}