#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <functional>
#include <map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

string aa, b;
string a;

int main()
{
	cin >> aa >> b;
	for (ll i = 0; i < aa.size(); i++)
		if (!('0' <= aa[i] && aa[i] <= '9')) a += aa[i];
	if (a.find(b) != string::npos) printf("1");
	else printf("0");
	return 0;
}