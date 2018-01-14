#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int> > s;

int main()
{
	int h = 0, m = 0;

	for(int i = 0; i < 720; i++)
	{
		h += 1; m += 12;
		if(h >= 360) h -= 360;
		if(m >= 360) m -= 360;
		s.insert(make_pair(h,m));
	}
	cin>>h>>m;
	if(s.find(make_pair(h,m)) != s.end()) cout<<"O";
	else cout<<"X";
	return 0;
}