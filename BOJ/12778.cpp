#include <iostream>

using namespace std;

int t;
int a[501];
char b[501];

int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		char x;
		scanf("%d %c", &n, &x); getchar();
		if (x == 'C')
		{
			for (int i = 0; i < n; i++) scanf("%c", b + i), getchar();
			for (int i = 0; i < n; i++) printf("%d ", (int)(b[i] - 'A' + 1));
		}
		else
		{
			for (int i = 0; i < n; i++) scanf("%d", a + i), getchar();
			for (int i = 0; i < n; i++) printf("%c ", a[i] + 'A' - 1);
		}
		putchar('\n');
	}
	return 0;
}