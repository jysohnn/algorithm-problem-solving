#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sq;
int d[100001];
int n;

int main()
{
	fill(d, d+100001, 999999); 	d[0] = 0;
	for(int i=0; i*i<=100000; i++) sq.push_back(i*i);
	for(int i=0; i<sq.size(); i++)
		for(int j=0; j<100001; j++)
			if(sq[i] + j < 100001) d[sq[i] + j] = min(d[sq[i] + j], d[j] + 1);
	cin>>n;
	cout<<d[n];
	return 0;
}