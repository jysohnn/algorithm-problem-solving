#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
int t;

int eureka(int x)
{
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.size();j++)
            for(int k=0;k<v.size();k++)
                if(v[i]+v[j]+v[k] == x) return 1;
    return 0;
}

int main()
{
    for(int i=1;i*(i+1)/2 < 1001;i++) v.push_back(i*(i+1)/2);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",eureka(n));
    }
    return 0;
}