#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 9999999

using namespace std;

struct gold
{
	int a;
	int b;
	int dis;
	gold(int _a,int _b,int _dis):a(_a),b(_b),dis(_dis){}
	bool operator<(const gold& g) const
	{
		if(dis < g.dis) return true;
		else return false;
	}
};

bool n[10001]={1,1,0};

int main()
{
	vector<int> p;
	for(int i=2;i<6001;i++)
		if(!n[i])
			for(int j=2;i*j<6001;j++) n[i*j]=true;
	for(int i=2;i<6001;i++)
		if(!n[i]) p.push_back(i);
	int t,size=p.size();
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		vector<gold> g;
		gold sol(0,INF,INF);
		int x;
		scanf("%d",&x);
		for(int j=0;j<size && p[j] <= x;j++)
			for(int k=j;k<size;k++)
				if(p[j]+p[k] == x) g.push_back(gold(p[j],p[k],p[k]-p[j]));
		for(int j=0;j<g.size();j++)
		{
			sol = min(sol,g[j]);
		}
		printf("%d %d\n",sol.a,sol.b);
	}
	return 0;
}