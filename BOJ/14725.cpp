#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

struct vtree
{
	string s;
	vector<vtree> v;
} root;

int n, k;

bool cmp(vtree& x, vtree& y) { return x.s < y.s; }
void make_tree(vtree& root, deque<string>& sv)
{
	if (sv.empty()) return;
	for (int i = 0; i < root.v.size(); i++)
	{
		if (root.v[i].s == sv[0])
		{
			sv.pop_front();
			make_tree(root.v[i], sv);
			return;
		}
	}
	vtree x; x.s = sv[0];
	root.v.push_back(x);
	sv.pop_front();
	make_tree(root.v[root.v.size()-1], sv);
}

void dfs(vtree& root, int level)
{
	for (int i = 0; i < level; i++) printf("--");
	cout << root.s; if(root.s != "") putchar('\n');
	sort(root.v.begin(), root.v.end(), cmp);
	for (int i = 0; i < root.v.size(); i++) dfs(root.v[i], level + 1);
}

int main()
{
	root.s = "";
	scanf("%d", &n);
	while (n--)
	{
		deque<string> sv;
		scanf("%d", &k);
		while (k--)
		{
			string tmp;
			cin >> tmp;
			sv.push_back(tmp);
		}
		make_tree(root, sv);
	}
	dfs(root, -1);
	return 0;
}