#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, ss;

int main()
{
	cin >> s;
	ss = s;
	reverse(s.begin(), s.end());
	if (s == ss) cout << "true";
	else cout << "false";
	return 0;
}