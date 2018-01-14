#include <bits/stdc++.h>

using namespace std;

int n, k;
long long d[201][201] = {0};

int main()
{
    cin>>n>>k;
    for(int i=0;i<=n;i++) d[i][1] = 1;
    for(int j=2;j<=k;j++)
        for(int x=0;x<=n;x++)
            for(int y=0;y<=n;y++)
                if(x+y <= n) d[x+y][j] += d[x][j-1], d[x+y][j] %= 1000000000;
    cout<<d[n][k];
    return 0;
}