#include <iostream>
#include <algorithm>

using namespace std;

int n, sum = 0, sol = -100000001;
int a[100001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) sum = max(sum + a[i], a[i]), sol = max(sol, sum);
	cout << sol;
	return 0;
}