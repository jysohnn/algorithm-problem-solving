#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int d[1001][1001];
string a,b;

int solve(int x, int y)
{
	int ret;
	if(x >= a.size() || y >= b.size()) return 0;
	if(d[x][y] != -1) return d[x][y];
	if(a[x] == b[y]) ret = 1 + solve(x+1,y+1);
	else ret = 0;
	return d[x][y] = max(ret ,max(solve(x+1,y), solve(x,y+1)));
}

int main()
{
	memset(d,-1,sizeof(d));
	cin>>a>>b;
	printf("%d",solve(0,0));
	return 0;
}