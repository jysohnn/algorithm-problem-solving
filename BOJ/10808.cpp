#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string str;
int a[26] = { 0 };

int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) a[str[i] - 'a']++;
	for (int i = 0; i < 26; i++) cout << a[i] << ' ';
	return 0;
}