#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int a[100001];
int w[100001];
stack<pair<int,int> > s;

int solve()
{
	int ret = 0;
	for(int i=0;i<n;i++)
	{
		int num = 1;
		while(!s.empty() && s.top().first >= a[i])
		{
			num += s.top().second;
			s.pop();
		}
		w[i] = num;
		s.push(make_pair(a[i],num));
	}
	while(!s.empty()) s.pop();
	for(int i=n-1;i>=0;i--)
	{
		int num = 1;
		while(!s.empty() && s.top().first >= a[i])
		{
			num += s.top().second;
			s.pop();
		}
		w[i] += (num-1);
		s.push(make_pair(a[i],num));
	}
	for(int i=0;i<n;i++) ret = max(ret, w[i] * a[i]);
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	printf("%d\n",solve());
	return 0;
}