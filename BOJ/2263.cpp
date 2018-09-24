#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> a, b;
int index[100001];

void solve(int as, int ae, int bs, int be)
{
	int mid;
	if(as > ae || bs > be) return;
	printf("%d ",b[be]);
	if(as == ae || bs == be) return;
	mid = index[b[be]];
	solve(as,mid-1,bs,mid-as-1+bs);
	solve(mid+1,ae,be+mid-ae,be-1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		index[x] = i;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	solve(0,n-1,0,n-1);
	return 0;
}