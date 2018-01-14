#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > v;

int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d",&k);
		v.push_back(vector<int>());
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		int a[51] = { 0 };
		int k, sol = 0;
		scanf("%d",&k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		for (int j = 0; j < n; j++)
		{
			int l;
			for (l = 0; l < v[j].size(); l++)
				if (!a[v[j][l]]) break;
			if (l == v[j].size()) sol++;
		}
		printf("%d\n",sol);
	}
	return 0;
}