#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, string> tiiis;
vector<tiiis> v;
int n;

bool comp(const tiiis& x, const tiiis& y)
{
	if (get<0>(x) > get<0>(y)) return 1;
	else if (get<0>(x) < get<0>(y)) return 0;
	else
	{
		if (get<1>(x) < get<1>(y)) return 1;
		else if (get<1>(x) > get<1>(y)) return 0;
		else
		{
			if (get<2>(x) > get<2>(y)) return 1;
			else if (get<2>(x) < get<2>(y)) return 0;
			else return get<3>(x) < get<3>(y);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char x[12];
		int a, b, c;
		scanf("%s %d %d %d", x, &a, &b, &c);
		v.push_back(make_tuple(a, b, c, string(x)));
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) cout << get<3>(v[i]) << '\n';
	return 0;
}