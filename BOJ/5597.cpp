#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

bool a[31] = { 0 };

int main()
{
	int x;
	for (int i = 0; i < 28; i++) cin >> x, a[x] = 1;
	for (int i = 1; i <= 30; i++)
		if (!a[i]) cout << i << endl;
	return 0;
}