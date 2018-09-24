#include <iostream>

using namespace std;
using ll = long long;

ll n, a[46] = { 1 }, b[46] = { 0 };

int main()
{
	for (int i = 1; i < 46; i++) a[i] = b[i - 1], b[i] = a[i - 1] + b[i - 1];
	cin >> n; cout << a[n] << ' ' << b[n];
	return 0;
}