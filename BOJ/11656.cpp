#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<string> v;

int main()
{
	cin >> str;
	for (int i = 0; i < str.size(); i++) v.push_back(str.substr(i, str.size()));
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';
	return 0;
}