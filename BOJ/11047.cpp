#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

ll n, k, sol = 0;
ll a[11];

int main()
{
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; i++) scanf("%lld",a+i);
	for (int i = n - 1; i >= 0 && k > 0;)
	{
		if (a[i] <= k) k -= a[i], sol++;
		else i--;
	}
	cout << sol;
	return 0;
}