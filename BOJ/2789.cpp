#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
set<char> s;
string str;

int main()
{
	s.insert('C');s.insert('A');s.insert('M');s.insert('B');s.insert('R');s.insert('I');s.insert('D');s.insert('G');s.insert('E');
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (s.find(str[i]) == s.end()) putchar(str[i]);
	return 0;
}