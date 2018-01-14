#include <iostream>

using namespace std;

int t, n;
int pre[1001], in[1001];

void solve(int ps, int pe, int is, int ie)
{
	if(ps > pe || is > ie) return;

	int v = pre[ps], x, y;
	for(x=is;x<=ie;x++)
		if(in[x] == v) break;
	int l = x - is;
	int r = ie - x;

	solve(ps+1,ps + l,is,is+l-1);
	solve(pe - r + 1,pe,ie-r+1,ie);
	printf("%d ",v);
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",pre+i);
		for(int i=0;i<n;i++) scanf("%d",in+i);
		solve(0,n-1,0,n-1); putchar('\n');
	}
	return 0;
}