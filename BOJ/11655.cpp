#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if ('a' <= str[i] && str[i] <= 'z') str[i] -= 'a', str[i] += 13, str[i] %= 26, str[i] += 'a';
		else if ('A' <= str[i] && str[i] <= 'Z') str[i] -= 'A', str[i] += 13, str[i] %= 26, str[i] += 'A';
		putchar(str[i]);
	}
	return 0;
}