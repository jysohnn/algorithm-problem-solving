#include <cstdio>
#include <cstring>

using namespace std;

int a[10001], b[10001];
long long sol = 0;

int main()
{
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	for(int i=0;1;i++)
	{
		char x;
		x = getchar();
		if(x == ' ') break;
		a[i] = x - '0';
	}
	for(int i=0;1;i++)
	{
		char x;
		x = getchar();
		if(x == '\n' || x == EOF) break;
		b[i] = x - '0';
	}
	for(int i=0;a[i]!=-1;i++)
		for(int j=0;b[j]!=-1;j++) sol += a[i]*b[j];
	printf("%lld",sol);
	return 0;
}