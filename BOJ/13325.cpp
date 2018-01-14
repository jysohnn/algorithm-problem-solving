#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long sol = 0, a[4194310];

long long solve(int x)
{
	if (a[x * 2] == -1 && a[x * 2 + 1] == -1) { sol += a[x]; return a[x]; }
	else if(a[x*2] == -1) { sol += a[x]; return a[x] + solve(x*2+1); }
	else if(a[x*2+1] == -1) { sol += a[x]; return a[x] + solve(x*2); }
	else
	{
		long long l = solve(x * 2), r = solve(x * 2 + 1);
		long long mmax = max(l, r), mmin = min(l, r);
		sol += (a[x] + mmax - mmin);
		return a[x] + mmax;
	}
}

int main()
{
	long long p = 1;
	scanf("%d", &n);
	memset(a, -1, sizeof(a));
	for (int i = 0; i < n+1; i++) p *= 2;
	a[1] = 0;
	for (int i = 2; i < p; i++) {int x; scanf("%lld",a+i);}
	solve(1);
	printf("%lld", sol);
	return 0;
}