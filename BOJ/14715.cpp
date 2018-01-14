#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int k;
bool prime[1000001] = {1,0};
int d[1000001] = {0,0,1,2,2};
vector<int> p;

int solve(int x)
{
	int ret = 0;
	for(int i=0;i<p.size() && x != 1;i++)
		if(x % p[i] == 0) x /= p[i], ret++, i--;
	return d[ret];
}

int main()
{
	for (int i = 2; i <= sqrt(1000000); i++)
	{ 
		if (prime[i] == 1) continue;
		for (int j = i + i; j <= 1000000; j += i) prime[j] = 1;
	}
	for(int i=2;i<1000001;i++)
		if(!prime[i]) p.push_back(i);

	for(int i=3; i<1000001; i++)
	{
		if(i % 2 == 0) d[i] = d[i/2] + 1;
		else d[i] = d[i/2 + 1] + 1;
	}

	cin>>k;
	cout<<solve(k);
	return 0;
}