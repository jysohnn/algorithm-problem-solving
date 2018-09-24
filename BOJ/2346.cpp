#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, c = 0, idx = 0;
vector<int> v;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	for(int k=0;k<n;k++)
	{
		int jump = 0;
		int tmp = v[idx];
		printf("%d ",idx+1);
		v[idx] = 0;
		if(k == n-1) break;
		if(tmp > 0)
			for(int i=idx;1;i++)
			{
				if(i >= n) i -= n;
				if(v[i] != 0) jump++;
				if(jump == tmp) {idx = i; break;}
			}
		else
			for(int i=idx;1;i--)
			{
				if(i < 0) i += n;
				if(v[i] != 0) jump++;
				if(-jump == tmp) {idx = i; break;}
			}
	}
	return 0;
}