#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

string x, y, sol;

int main()
{
	cin >> x >> y; if (x.size() < y.size()) swap(x, y);
	
	int carry = 0;
	int i = x.size() - 1;
	for (int j = y.size() - 1; j >= 0; i--, j--)
	{
		int sum = x[i] + y[j] + carry - '0' * 2;
		carry = sum / 10; sum %= 10;
		sol.push_back(sum + '0');
	}
	for (; i >= 0; i--)
	{
		int sum = x[i] + carry - '0';
		carry = sum / 10; sum %= 10;
		sol.push_back(sum + '0');
	}
	if (carry) sol.push_back('1');
	reverse(sol.begin(), sol.end());
	cout << sol;
	return 0;
}