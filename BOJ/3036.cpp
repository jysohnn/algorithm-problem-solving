#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, k;

void solve(int x, int y)
{
	for (int i = 2; i <= min(x, y); i++)
		if (x % i == 0 && y % i == 0) x /= i, y /= i, i--;
	printf("%d/%d\n", y, x);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++)
	{
		int x; scanf("%d", &x);
		solve(x, k);
	}
	return 0;
}