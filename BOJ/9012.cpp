#include <cstdio>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;
vector<char> v;
char a[53];
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		v.clear();
		scanf("%s", a);
		int flag = 1;
		int len = strlen(a);
		for (int i = 0; i < len; i++)
		{
			if (a[i] == '(') v.push_back('(');
			else if (a[i] == ')')
			{
				if (v.size() == 0)
				{
					flag = 0;
					break;
				}
				if (v.back() == '(') v.pop_back();
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if (v.size() != 0 || flag == 0) puts("NO");
		else puts("YES");
	}
	return 0;
}