#include <iostream>
#include <string>
#include <functional>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
set<string> s;
priority_queue<string, vector<string>, greater<string> > q;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string x; cin >> x;
		s.insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		string x; cin >> x;
		if (s.find(x) != s.end()) q.push(x);
	}
	cout << q.size() << endl;
	while(!q.empty()) cout << q.top() << endl, q.pop();
	return 0;
}