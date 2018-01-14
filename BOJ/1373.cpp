#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> v, sol;

int main()
{
    int x, count = 0, n = 0;
    while(scanf("%1d",&x)!=EOF) v.push_back(x);
    for(auto it = v.rbegin();it != v.rend(); it++)
    {
        n += *it * (1<<count);
        count++;
        if(count == 3) count = 0, sol.push_back(n), n = 0;
    }
    if(n != 0) sol.push_back(n);
    for(auto it = sol.rbegin();it != sol.rend(); it++) printf("%d",*it);
    return 0;
}