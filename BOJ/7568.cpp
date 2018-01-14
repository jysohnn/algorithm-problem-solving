#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<pair<int, int> > v;

bool cmp(pair<int,int> x, pair<int,int> y)
{
    if(x.first < y.first && x.second < y.second) return 1;
    else return 0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x, y;
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    for(int i=0;i<v.size();i++)
    {
        int sol = 1;
        for(int j=0;j<v.size();j++)
            if(cmp(v[i],v[j])) sol++;
        printf("%d ",sol);
    }
    return 0;
}