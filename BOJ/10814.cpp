#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct x
{
	int first;
	string second;
	int idx;
} a[100001];

bool operator<(const x& a,const x& b)
{
	if(a.first < b.first) return true;
	else if(a.first == b.first)
	{
		if(a.idx < b.idx) return true;
		else return false;
	}
	else return false;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {cin>>a[i].first>>a[i].second;a[i].idx=i;}
	sort(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i].first<<' '<<a[i].second<<endl;
	return 0;
}