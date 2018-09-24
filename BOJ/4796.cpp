#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

ll l, p, v;

int main()
{
	for (int t = 1; 1; t++)
	{
		scanf("%lld %lld %lld", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0) break;
		printf("Case %d: %lld\n", t, (v / p) * l + min((v % p), l));
	}
	return 0;
}