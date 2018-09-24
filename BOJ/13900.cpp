#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, sum = 0;
ll a[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%lld", a + i), sum += a[i];
	sum *= sum;
	for (int i = 0; i < n; i++) sum -= a[i] * a[i];
	sum /= 2;
	cout << sum;
	return 0;
}