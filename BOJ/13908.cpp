#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;

bool check_n(int num,int n)
{
    bool check=true;
    bool x[10]={0};
    for(int i=n-1;i>=0;i--)
    {
        int div=1;
        for(int j=0;j<i;j++) div*=10;
        x[(num/div)%10] = true;
    }
    for(int i=0;i<v.size();i++)
    {
        if(!x[v[i]]) check=false;
    }
    return check;
};

int main()
{
    int n,m;
    int max=1,check=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    for(int i=0;i<n;i++) max*=10;
    for(int i=0;i<max;i++)
    {
        if(check_n(i,n)) check++;
    }
    printf("%d",check);
    return 0;
}