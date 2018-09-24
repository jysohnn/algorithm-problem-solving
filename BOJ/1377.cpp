#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;


pii a[500001];
int n, sol = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i].first), a[i].second = i;
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].second > i) sol = max(sol, a[i].second - i);
		else if(a[i].second < i) sol = max(sol, 1);
	}
	printf("%d", sol + 1);
	return 0;
}