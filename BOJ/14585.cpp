#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<pair<int,int> > v;
int start[303];
int adj[303][303];
int sol = 0;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,b));
    }   
    for(int i=0;i<n;i++) start[i] = m - (v[i].first + v[i].second);
    for(int i=0;i<303;i++)
        for(int j=0;j<303;j++) adj[i][j] = -999999999;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(v[i].first <= v[j].first && v[i].second <= v[j].second)
            {
                adj[i][j] = (m - (v[j].first+v[j].second));
                if(adj[i][j] < 0) adj[i][j] = 0;
            }   
    for(int i=0;i<n;i++) adj[i][i] = 0;
    for(int k=0;k<n;k++) 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(adj[i][k] + adj[k][j] > adj[i][j]) adj[i][j] = adj[i][k] + adj[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(sol < start[i] + adj[i][j]) sol = start[i] + adj[i][j];
    printf("%d",sol);
    return 0;
}