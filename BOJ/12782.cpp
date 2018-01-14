#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
string a, b;
int t;

int main()
{
	cin >> t;
	while (t--)
	{
		int o = 0, z = 0;
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '1' && a[i] != b[i]) o++;
			else if(a[i] == '0' && a[i] != b[i]) z++;
		}
		cout << max(o, z) << '\n';
	}
	return 0;
}