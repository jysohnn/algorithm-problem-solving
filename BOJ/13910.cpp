#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x[20001]={0};
int d[10001]={0};

int main()
{
	int i,j,k;
	int n,wn;
	vector<int> v;
	
	scanf("%d %d",&n,&wn);
	int* w=new int[wn];
	for(i=0;i<wn;i++) scanf("%d",w+i);
	for(i=0;i<wn;i++)
		for(j=i+1;j<wn;j++) x[w[i]+w[j]]=1;
	for(i=0;i<wn;i++) x[w[i]]=1;
	for(i=0;i<10001;i++)
		if(x[i]) v.push_back(i);

	for(i=0;i<v.size();i++) d[v[i]]=1;
	for(i=1;1;i++)
	{
		vector<int> vv;
		for(j=0;j<10001;j++)
			if(d[j]==i) vv.push_back(j);
		if(vv.empty()) break;
		for(j=0;j<v.size();j++)
			for(k=0;k<vv.size();k++)
				if(v[j]+vv[k]<10001 && d[v[j]+vv[k]]==0)
				{
					d[v[j]+vv[k]]=i+1;
				}
	}
	for(i=0;i<10001;i++)
		if(d[i]==0) d[i]=-1;
	printf("%d",d[n]);
	return 0;
}