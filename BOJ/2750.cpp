#include <iostream>
#include <algorithm>

using namespace std;

const int nsize = 1000001;
int n, a[nsize];

void my_sort(int s, int e)
{
	if (s >= e - 1) return;
	else
	{
		int* tmp = new int[nsize];
		int m = (s + e) / 2, idx = 0;
		int x = s, y = m;
		my_sort(s, m); my_sort(m, e);
		while (x != m || y != e)
		{
			if (x != m && y != e)
			{
				if(a[x] > a[y]) tmp[idx++] = a[y++];
				else tmp[idx++] = a[x++];
			}
			else if (x == m) while (y != e) tmp[idx++] = a[y++];
			else while (x != m) tmp[idx++] = a[x++];
		}
		for (int i = s; i < e; i++) a[i] = tmp[i - s];
		delete []tmp;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	my_sort(0, n);
	for (int i = 0; i < n; i++) printf("%d\n", a[i]);
	return 0;
}