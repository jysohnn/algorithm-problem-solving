#include <iostream>
#include <algorithm>

using namespace std;

int h, w;
int a[501], l[501], r[501];
int lm = 0, rm = 0, sol = 0;

int main()
{
	cin >> h >> w;
	for (int i = 0; i < w; i++) scanf("%d", a + i);
	for (int i = 0; i < w; i++) l[i] = lm, lm = max(a[i], lm);
	for (int i = w-1; i >= 0; i--) r[i] = rm, rm = max(a[i], rm);
	for (int i = 0; i < w; i++) sol += max(min(l[i], r[i]) - a[i], 0);
	cout << sol;
	return 0;
}