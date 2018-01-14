#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

bool bs(int target,int l,int r)
{
	if(l>r) return false;
	int mid = (l+r)/2;
	if(target == v[mid]) return true;
	else if(target > v[mid]) return bs(target,mid+1,r);
	else return bs(target,l,mid-1);
}

int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if(bs(x,0,v.size()-1)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}