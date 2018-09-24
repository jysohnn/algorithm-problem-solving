#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

string s[3], str;

int main()
{
	cin >> str;
	for (int i = 1; i <= str.size(); i++)
	{
		if (i % 3 == 0) s[0] += string("..*.");
		else s[0] += string("..#.");
	} s[0].push_back('.');
	for (int i = 1; i <= str.size(); i++)
	{
		if (i % 3 == 0) s[1] += string(".*.*");
		else s[1] += string(".#.#");
	} s[1].push_back('.');
	for (int i = 1; i <= str.size(); i++)
	{
		if (i % 3 == 0) s[2] += string("*."), s[2].push_back(str[i-1]), s[2].push_back('.');
		else s[2] += string("#."), s[2].push_back(str[i - 1]), s[2].push_back('.');
	}
	if (str.size() % 3 == 0) s[2].push_back('*');
	else s[2].push_back('#');
	for (int i = 0; i < str.size() / 3; i++)
		s[2][i * 12 + 8] = '*', s[2][i * 12 + 12] = '*';
	cout << s[0] << '\n' << s[1] <<'\n' << s[2] << '\n' << s[1] << '\n' << s[0];
	return 0;
}