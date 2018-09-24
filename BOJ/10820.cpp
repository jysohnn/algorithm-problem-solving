#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	while (1)
	{
		string str;
		int a = 0, b = 0, c = 0, d = 0;

		if (!getline(cin, str)) break;
		for (int i = 0; i < str.size(); i++)
		{
			char x = str[i];
			if ('a' <= x && x <= 'z') a++;
			else if ('A' <= x && x <= 'Z') b++;
			else if ('0' <= x && x <= '9') c++;
			else if (x == ' ') d++;
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}
	return 0;
}