#include <iostream>
#include <vector>

using namespace std;

int n;
long long power[10] = {0};
vector<long long> v[10][10];
vector<long long> sol;

long long ppp(int x)
{
    long long ret = 1;
    if(power[x] != 0) return power[x];
    for(int i=0;i<x;i++) ret *= 10;
    return power[x] = ret;
}

int main()
{
    for(int i=0;i<10;i++) v[0][i].push_back(i);
    for(int i=1;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<j;k++)
                for(int l=0;l<v[i-1][k].size();l++)
                    v[i][j].push_back(v[i-1][k][l] + j * ppp(i));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<v[i][j].size();k++) sol.push_back(v[i][j][k]);
    cin>>n;
    if(n >= sol.size()) cout<<-1;
    else cout<<sol[n];
    return 0;
}