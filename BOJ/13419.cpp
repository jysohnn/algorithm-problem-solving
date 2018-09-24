#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		string pat;
		cin >> pat;
		if (pat.size() % 2 == 0)
		{
			for (int i = 0; i < pat.size(); i += 2) putchar(pat[i]);
			putchar('\n');
			for (int i = 1; i < pat.size(); i += 2) putchar(pat[i]);
			putchar('\n');
		}
		else
		{
			for (int i = 0; i < pat.size(); i++) putchar(pat[(i * 2) % pat.size()]);
			putchar('\n');
			for (int i = 0; i < pat.size(); i++) putchar(pat[(i * 2 + 1) % pat.size()]);
			putchar('\n');
		}
	}
	return 0;
}