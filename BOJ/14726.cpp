#include <iostream>
#include <string>

using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--)
	{
		int sum = 0;
		string str;
		cin >> str;
		for (int i = 15; i >= 0; i--)
		{
			int tmp = str[i] - '0';
			if (i % 2 == 0)
			{
				tmp *= 2;
				if (tmp >= 10) tmp %= 10, tmp++;
			}
			sum += tmp;
		}
		if (sum % 10 == 0) printf("T\n");
		else printf("F\n");
	}
	return 0;
}