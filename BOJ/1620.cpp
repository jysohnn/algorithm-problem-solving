#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

map<string, string> x;
ll n, m;

int main()
{
    cin>>n>>m;
    for(ll i=1; i<=n; i++)
    {
        char str[101];
        scanf("%s", str);
        string s = string(str);
        string ii = to_string(i);
        x.insert({s, ii});
        x.insert({ii, s});
    }
    for(ll i=1; i<=m; i++)
    {
        char str[101];
        scanf("%s", str);
        string s = string(str);
        printf("%s\n", x[s].c_str());
    }
    return 0;
}