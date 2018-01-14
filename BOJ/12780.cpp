#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
string str, pat;

int main()
{
	ll sol = 0;
	ll x = 0;
	cin >> str >> pat;
	while (1)
	{
		x = (ll)str.find(pat, x);
		if (x == string::npos) break;
		x += (pat.length());
		sol++;
	}
	cout << sol;
	return 0;
}