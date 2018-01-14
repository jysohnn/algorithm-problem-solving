#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct edge
{
	int x;
	int y;
	long long cost;
	
	edge(int a, int b, int c) :x(a),y(b),cost(c) {};
	bool operator>(const edge& e) const
	{
		if(cost>e.cost) return true;
		else return false;
	};
};

int* p;

int find(int x)
{
	if(p[x] == x) return x;
	p[x] = find(p[x]);
	return p[x];
};

bool union_f(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return false;
	else
	{
		p[x]=y;
		return true;
	}
};

bool Isthereloop(edge& e)
{
	return !union_f(e.x,e.y);
};

int main()
{
	int n,m;
	vector<edge> e,sol;
	
	scanf("%d %d",&n,&m);
	p = new int[n];
	for(int i=0;i<n;i++) p[i]=i;
	for(int i=0;i<m;i++)
	{
		int x,y,cost;
		scanf("%d %d %d",&x,&y,&cost);
		e.push_back(edge(x-1,y-1,cost));
	}
	
	sort(e.begin(),e.end(),greater<edge>());
	
	while(sol.size()+1!=n)
	{
		edge tmp=e.back();
		e.pop_back();
		if(!Isthereloop(tmp))
		{
			sol.push_back(tmp);
		}
	}
	
	if(n==1) printf("0");
	else
	{
		long long ssol=0;
		for(int i=0;i<sol.size();i++) ssol+=sol[i].cost;
		printf("%lld",ssol);
	}
	
	return 0;
}