#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int x, y;
	scanf("%d:%d",&x,&y);
	for (int i = 2; i < max(x, y); i++)
		if (x%i == 0 && y%i == 0) x /= i, y /= i, i--;
	printf("%d:%d",x,y);
}