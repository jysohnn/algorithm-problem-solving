#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

int t;
string s;

bool sol(string& s)
{
	if (s.size() == 1) return true;

	string ss;
	for (int i = 2; i < s.size(); i += 2)
		if (s[i] == s[i - 2]) return false;
	for (int i = 1; i < s.size(); i += 2) ss.push_back(s[i]);

	return sol(ss);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		if (sol(s)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}