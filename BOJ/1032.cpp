#include <iostream>
#include <string>

using namespace std;

int n;
string s[51], sol;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < s[0].size(); i++)
	{
		char tmp = s[0][i];
		bool flag = 0;
		for (int j = 0; j < n; j++)
			if (s[j][i] != tmp) flag = 1;
		if (flag) sol.push_back('?');
		else sol.push_back(tmp);
	}
	cout << sol;
	return 0;
}