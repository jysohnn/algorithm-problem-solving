#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool solve(int x)
{
	for (int i = 2; i <= 64; i++)
	{
		int tmp = x;
		vector<int> v, rv;
		while (tmp) v.push_back(tmp%i), tmp /= i;
		rv = v;
		reverse(rv.begin(), rv.end());
		if (v == rv) return 1;
	}
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d",&x);
		if (solve(x)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}