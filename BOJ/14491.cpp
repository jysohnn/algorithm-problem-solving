#include <cstdio>
#include <algorithm>

using namespace std;

int a[100] = { 0 };

int main()
{
	int x,i;
	scanf("%d",&x);
	for(i=0;x;i++)
	{
		a[i] = x % 9;
		x /= 9;
	}
	for (i = 99;!a[i]; i--);
	for (int j = i; j >= 0; j--) printf("%d",a[j]);
}