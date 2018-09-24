#include <cstdio>
#include <algorithm>

using namespace std;

bool a[301][301] = { 0 };
bool b[301][301] = { 0 };
bool c[301][301] = { 0 };
int n, sol = 0;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d",&x);
			if (x) a[i][j] = true;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			if (x) b[i][j] = true;
		}
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++) c[i][j] = c[i][j] | (a[i][k] & b[k][j]);
			if (c[i][j]) sol++;
		}
	printf("%d",sol);
}