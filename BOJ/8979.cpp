#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;
using ll = long long;
using t = tuple<int, int, int, int>;

vector<t> v;
ll n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == k) a = 100001;
		v.push_back({ b,c,d,a });
	}
	sort(v.begin(), v.end(), greater<t>());
	for(int i=0;i<v.size();i++)
		if (get<3>(v[i]) == 100001) printf("%d", i + 1);
	return 0;
}