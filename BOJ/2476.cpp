#include <iostream>
#include <algorithm>

using namespace std;

int n, sol = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int reward;
		int x, y, z; scanf("%d %d %d", &x, &y, &z);
		if (x == y && y == z) reward = 10000 + x * 1000;
		else if(x == y) reward = 1000 + x * 100;
		else if(y == z) reward = 1000 + y * 100;
		else if(z == x) reward = 1000 + z * 100;
		else reward = max({ x, y, z }) * 100;
		if (reward > sol) sol = reward;
	}
	cout << sol;
	return 0;
}