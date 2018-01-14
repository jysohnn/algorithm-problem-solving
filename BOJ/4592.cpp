#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> sol;

int main()
{
    while(1)
    {
        v.clear();
        sol.clear();
        scanf("%d",&n);
        if(!n) break;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        int prev = -1;
        for(int i=0;i<v.size();i++)
            if(v[i] != prev) sol.push_back(v[i]), prev = v[i];
        for(int i=0;i<sol.size();i++) printf("%d ",sol[i]);
        printf("$\n");
    }
    return 0;
}