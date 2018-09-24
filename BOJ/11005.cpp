#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, b;
vector<char> v;

int main()
{
    cin>>n>>b;
    while(n)
    {
        v.push_back(n%b);
        n /= b;
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i] > 9) printf("%c",v[i]-10+'A');
        else printf("%d",v[i]);
    }
    return 0;
}