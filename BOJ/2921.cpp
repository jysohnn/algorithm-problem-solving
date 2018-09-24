#include <iostream>

using namespace std;
typedef long long ll;

ll n, sol = 0;

int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
		for (int j = i; j <= n; j++) sol += (i + j);
	cout << sol;
	return 0;
}