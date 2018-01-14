#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { int x; scanf("%d", &x); v.push_back(x); }
	printf("%d %d", *min_element(v.begin(), v.end()), *max_element(v.begin(), v.end()));
	return 0;
}