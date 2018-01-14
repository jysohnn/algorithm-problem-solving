#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int n = 10000001;
bool prime[n] = {1,1,0};
vector<long long> p;
vector<long long> pp;
long long a, b;
long long sol = 0;
bool flag = false;

int main()
{
    for(int i=2;i<n;i++)
    {
        if(!prime[i])
        {
            p.push_back(i);
            for(int j=2;i*j<n;j++) prime[i*j] = 1;
        }
    }
    for(int i=0;i<p.size();i++)
    {
        long long x = p[i];
        long long y = x*x;
        while(y < 100000000000001)
        {
            pp.push_back(y);
            if(y >= 100000000000001.0 / (double)x) break;
            y *= x;
        }
    }
    sort(pp.begin(),pp.end());
    scanf("%lld %lld",&a,&b);
    for(int i=0;i<pp.size();i++)
    {
        if(pp[i] >= a) flag = true;
        if(flag && pp[i] <= b) sol++;
    }
    printf("%lld",sol);
    return 0;
}