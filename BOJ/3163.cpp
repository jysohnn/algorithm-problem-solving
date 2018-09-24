#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque<pair<int, int>> d; //현위치/아이디
vector<pair<int, int>> v; //남은거리/아이디
int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,l,k;
		v.clear();
		d.clear();
		scanf("%d%d%d",&n,&l,&k);
		for(int i=0; i<n; i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			d.push_back(make_pair(a,b));
			if( b >= 0) v.push_back(make_pair(l-a,b));
			else v.push_back(make_pair(a,b));
		}
		sort(d.begin(),d.end());
		sort(v.begin(),v.end());
		//
		pair<int, int> poped;
		for(int i=0; i<n; i++)
		{
			if( i < n -1 && v[i].first == v[i+1].first )
			{
				if( d.front().second < d.back().second )
				{
					poped = d.front();
					d.pop_front();
					if( i + 1 == k) break;
					i++;
					poped = d.back();
					d.pop_back();
					if( i+1 == k) break;
				}
				else
				{
					poped = d.back();
					d.pop_back();
					if( i + 1 == k) break;
					i++;
					poped = d.front();
					d.pop_front();
					if( i+1 == k) break;
				}
			}
			else if(v[i].second > 0)
			{
				poped = d.back();
				d.pop_back();
				if( i +1 == k) break;
			}
			else
			{
				poped = d.front();
				d.pop_front();
				if( i +1 == k) break;
			}
		}
		printf("%d\n",poped.second);
	}
	return 0;

}