#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, sol = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	do
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
		{
			int tmp = v[i] - v[i - 1];
			if (tmp < 0) tmp *= -1;
			sum += tmp;
		}
		sol = max(sol, sum);
	} while ((next_permutation(v.begin(), v.end())));
	printf("%d", sol);
	return 0;
}