#include <cstdio>
#include <algorithm>

using namespace std;

int n, a[100001], pre = -1001;
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		if (pre != a[i]) printf("%d ",a[i]), pre = a[i];
	return 0;
}