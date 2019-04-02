#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <functional>
#include <map>
#include <ctime>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n, m;
map<string, vector<string> > member;
map<string, string> team;

int main()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	cout <<1900 + ltm->tm_year << endl;
	printf("%02d\n", 1 + ltm->tm_mon);
	printf("%02d\n", ltm->tm_mday);
	return 0;
}