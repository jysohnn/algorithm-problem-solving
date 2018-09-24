#include <cstdio>
#include <vector>

using namespace std;

int n, m;
int a[1001];
int b[1001];
vector<int> f;
vector<int> s;

int mmin = 1001, mmax = -1001;

void check(int num, int prev, int dis)
{
	if(num == n)
	{
		if(mmin > dis) mmin = dis;
		if(mmax < dis) mmax = dis;
		return;
	}
	for(int i=prev+1;i<m;i++)
	{
		if(b[i] == a[num] && i-prev-1 == dis) check(num+1, i, dis);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%d",b+i);
	for(int i=0;i<m;i++)
	{
		if(b[i] == a[0]) f.push_back(i);
		if(b[i] == a[1]) s.push_back(i);
	}
	for(int i=0;i<f.size();i++)
		for(int j=0;j<s.size();j++)
			if(f[i] < s[j])	check(2,s[j],s[j]-f[i]-1);
	if(mmax == -1001 || mmin == 1001 ) printf("-1");
	else printf("%d %d",mmin, mmax);
	return 0;
}