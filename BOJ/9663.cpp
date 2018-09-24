#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int n, sol = 0;
int a[16] = { 0 };

bool promising(int x)
{
	for (int i = 0; i < x; i++)
		if (a[i] == a[x] || abs(a[x] - a[i]) == x - i) return 0;
	return 1;
}

void solve(int x)
{
	if (promising(x))
	{
		if (x == n - 1) sol++;
		for (int i = 0; i < n; i++) a[x + 1] = i, solve(x + 1);
	}
}

int main()
{
	scanf("%d", &n);;
	solve(-1);
	printf("%d", sol);
	return 0;
}