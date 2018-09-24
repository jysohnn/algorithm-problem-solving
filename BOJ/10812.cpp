#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> v;

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) v.push_back(i);
	for(int i=0;i<m;i++)
	{
		int s,e,k;
		scanf("%d %d %d",&s,&e,&k);
		rotate(v.begin()+s-1,v.begin()+k-1,v.begin()+e);
	}
	for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	return 0;
}