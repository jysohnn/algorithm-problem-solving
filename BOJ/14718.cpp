#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll a[101][3];
vector<ll> x,y,z;
ll n,kk;
ll m = 90000001;

int main()
{
    cin>>n>>kk;
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
        x.push_back(a[i][0]);
        y.push_back(a[i][1]);
        z.push_back(a[i][2]);
    }

    for(int i=0;i<x.size();i++)
        for(int j=0;j<y.size();j++)
            for(int k=0;k<z.size();k++)
            {
                int check = 0;
                for(int l=0;l<n;l++)
                    if(x[i] >= a[l][0] && y[j] >= a[l][1] && z[k] >= a[l][2]) check++;
                if(check >= kk && m > x[i] + y[j] + z[k]) m = x[i] + y[j] + z[k];
            }
    cout<<m;
    return 0;
}