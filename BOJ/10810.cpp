#include <iostream>

using namespace std;

int n, m;
int a[101];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k; x--;
		for (int j = x; j < y; j++) a[j] = k;
	}
	for (int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}