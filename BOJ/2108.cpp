#include <cstdio>
#include <vector>

using namespace std;

int n;
int pint[4001]={0};
int nint[4001]={0};
vector<int> a;

double mean()
{
	double sum=0;
	for(int i=0;i<n;i++) sum += a[i];
	return sum/(double)n;
}
int median() {return a[(n-1)/2];}
int most()
{
	int max=0;
	vector<int> m;
	for(int i=4000;i>=0;i--)
		if(nint[i] > max) max = nint[i];
	for(int i=0;i<4001;i++)
		if(pint[i] > max) max = pint[i];
	for(int i=4000;i>=0;i--)
		if(nint[i] == max) m.push_back(-i);
	for(int i=0;i<4001;i++)
		if(pint[i] == max) m.push_back(i);
	if(m.size() > 1) return m[1];
	else return m[0];
}
int range(){return a[n-1]-a[0];}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x>=0) pint[x]++;
		else nint[-x]++;
	}
	for(int i=4000;i>=0;i--)
		for(int j=0;j<nint[i];j++) a.push_back(-i);
	for(int i=0;i<4001;i++)
		for(int j=0;j<pint[i];j++) a.push_back(i);
	
	printf("%.0lf\n%d\n%d\n%d\n",mean(),median(),most(),range());
	return 0;
}