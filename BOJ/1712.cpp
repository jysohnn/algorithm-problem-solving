#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

double a, b, c;

int main()
{
	cin >> a >> b >> c;
	if (c <= b) printf("-1");
	else printf("%lld",(ll)(a/(c-b)) + 1);
	return 0;
}