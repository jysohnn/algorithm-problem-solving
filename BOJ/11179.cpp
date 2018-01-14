#include <cstdio>
#include <vector>

using namespace std;

int n, sol = 0;
vector<int> v;

void makeBin(int x)
{
    if(x == 0) return;
    v.push_back(x%2);
    makeBin(x/2);
}

int main()
{
    scanf("%d",&n);
    makeBin(n);
    for(int i=0;i<v.size();i++)
    {
        sol *= 2;
        sol += v[i];
    }
    printf("%d",sol);
    return 0;
}