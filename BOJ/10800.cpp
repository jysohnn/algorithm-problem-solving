#include <cstdio>
#include <vector>

using namespace std;

struct ball
{
	int color;
	int size;
};

vector<ball> v[200001];
int t[2001] = { 0 };
ball a[200001];
int n;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&a[i].color,&a[i].size);
		v[a[i].color].push_back(a[i]);
		t[a[i].size]++;
	}
	t[0] = 0;
	for (int i = 1; i < 2001; i++) t[i] = i*t[i] + t[i-1];
	for (int i = 0; i < n; i++)
	{
		int sol = t[a[i].size -1];
		for (int j = 0; j < v[a[i].color].size(); j++)
			if(v[a[i].color][j].size < a[i].size) sol -= v[a[i].color][j].size;
		printf("%d\n",sol);
	}
	return 0;
}