#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <functional>
#include <map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m;
map<string, vector<string> > member;
map<string, string> team;

int main()
{
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n; i++)
	{
		ll cnt;
		char tmp[201];
		scanf("%s", tmp);
		string team_name(tmp);
		scanf("%lld", &cnt);
		member[team_name] = vector<string>();
		for (ll j = 0; j < cnt; j++)
		{
			char tmp[201];
			scanf("%s", tmp);
			string member_name(tmp);
			member[team_name].push_back(member_name);
			team[member_name] = team_name;
		}
		sort(member[team_name].begin(), member[team_name].end());
	}
	for (ll i = 0; i < m; i++)
	{
		char tmp[201];
		ll flag;
		scanf("%s %lld", tmp, &flag);
		string name(tmp);

		if (flag == 1)
		{
			printf("%s\n", team[name].c_str());
		}
		else
		{
			for (ll j = 0; j < member[name].size(); j++)
			{
				printf("%s\n", member[name][j].c_str());
			}
		}
	}
	return 0;
}