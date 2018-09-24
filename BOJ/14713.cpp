#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

int n;
vector<string> v[101];
map<string, int> t;

int main()
{
	scanf("%d",&n); getchar();
	string str;
	int count = 0;
	while(1)
	{
		char x = getchar();
		if(x == ' ')
		{
			v[count].push_back(str);
			str.clear();
		}
		else if(x == '\n')
		{
			v[count].push_back(str);
			str.clear();
			count++;
			if(count == n) break;
		}
		else str.push_back(x);
	}
	count = 0;
	while(1)
	{
		char xx[38];
		if(scanf("%s",xx) == EOF) break;
		string tmp(xx);
		t.insert(make_pair(tmp, count++));
	}
	count = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<v[i].size() - 1; j++)
		{
			if(t.find(v[i][j]) == t.end() || 
			   t.find(v[i][j+1]) == t.end())
			{
				printf("Impossible");
				return 0;
			}
			if(t[v[i][j]] > t[v[i][j+1]])
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	int sum = 0;
	for(int i=0;i<n;i++) sum += v[i].size();
	if(sum != t.size()) printf("Impossible");
	else printf("Possible");
	return 0;
}