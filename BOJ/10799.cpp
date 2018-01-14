#include <iostream>
#include <string>

using namespace std;

string str;
int sol = 0, s = 0;

int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') s++;
		else if(str[i-1] == '(') s--, sol += s;
		else s--, sol++;
	}
	cout << sol;
	return 0;
}