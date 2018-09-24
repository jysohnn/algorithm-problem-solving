#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> sol;
int count = 0;
int fail[1000001];

void failure(char* p)
{
	int i;
	fail[0] = -1;
	for(i=1;p[i]!=0;i++)
	{
		int j = fail[i-1];
		while(p[i]!=p[j+1] && j>=0) j = fail[j];
		if(p[i] == p[j+1]) fail[i] = j+1;
		else fail[i] = -1;
	}
}

void pmatch(char* t,char* p)
{
	int i,j;
	int plast = strlen(p) - 1;
	failure(p);
	for(i=0,j=0;t[i]!=0;)
	{
		if(t[i] == p[j])
		{
			i++;j++;
			if(j > plast)
			{
				count++;
				sol.push_back(i-plast);
				j = fail[j-1] + 1;
			}
		}
		else if(j == 0) i++;
		else j = fail[j-1] + 1;
	}
}

int main()
{
	int i;
	char t[1000001],p[1000001];
	gets(t);
	gets(p);
	pmatch(t,p);
	printf("%d\n",count);
	for(i=0;i<sol.size();i++) printf("%d ",sol[i]);
	return 0;
}