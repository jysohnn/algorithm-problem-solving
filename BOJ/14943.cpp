#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll n, sol = 0;
ll a[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i] + a[i - 1];
		sol += abs(a[i - 1]);
	}
	cout << sol;
	return 0;
}