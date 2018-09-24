#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> v;
int n;

bool comp(const string& x, const string& y)
{
	if (x.size() < y.size()) return 1;
	else if (x.size() > y.size()) return 0;
	else return x < y;
}

int main()
{
	cin >> n;
	while (n--) { string x; cin >> x; v.push_back(x); }
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++)
		if(i == 0 || v[i] != v[i-1]) cout << v[i] << '\n';
	return 0;
}