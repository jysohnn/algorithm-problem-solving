#include <cstdio>
#include <list>

using namespace std;

list<char> l;
int n;

int main()
{
	while (1)
	{
		char x = getchar();
		if (x == '\n') break;
		l.push_back(x);
	}
	auto it = l.end();
	scanf("%d", &n); getchar();
	for (int i = 0; i<n; i++)
	{
		char x = getchar();
		switch (x)
		{
		case 'L': if (it != l.begin()) it--; break;
		case 'D': if (it != l.end()) it++; break;
		case 'B': if (it != l.begin()) it = l.erase(--it); break;
		case 'P': getchar(); x = getchar(); it = l.insert(it, x); it++; break;
		default: break;
		}
		getchar();
	}
	for (auto it = l.begin(); it != l.end(); it++) printf("%c", *it);
	return 0;
}