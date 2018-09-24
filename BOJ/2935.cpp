#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

string x, y, op;

string add(string& x, string& y)
{
	if (x.size() > y.size()) swap(x, y);
	for (int i = x.size()-1, j = y.size()-1; i >= 0; i--, j--) y[j] += (x[i] - '0');
	return y;
}
string multi(string& x, string& y)
{
	if (x == "0" || y == "0") return string("0");
	int size = x.size() + y.size() - 2;
	string ret = string("1");
	for (int i = 0; i < size; i++) ret += string("0");
	return ret;
}

int main()
{
	cin >> x >> op >> y;
	if (op == "*") cout << multi(x, y);
	else cout << add(x, y);
	return 0;
}