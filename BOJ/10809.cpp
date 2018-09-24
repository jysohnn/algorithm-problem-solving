#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
string str;
int a[26] = { 0 };

int main()
{
	cin >> str;
	memset(a, -1, sizeof(a));
	for (int i = 0; i < str.size(); i++)
		if (a[str[i] - 'a'] == -1) a[str[i] - 'a'] = i;
	for (int i = 0; i < 26; i++) cout << a[i] << ' ';
	return 0;
}