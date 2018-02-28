#include <bits/stdc++.h>

using namespace std;

int n;
int dp[101][101][2];
int a[101];

int solve(int s, int e, int x)
{
    if(dp[s][e][x] != -1) return dp[s][e][x];
    if(s == e) return dp[s][e][x] = (x == a[s]) ? 1 : 0;
    int mid = (s+e)/2;
    return dp[s][e][x] = solve(s,mid,x) + solve(mid+1,e,x);
}

int main()
{
    int sol = 0;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n-1;i++) sol = max(sol, solve(0,i,0) + solve(i+1,n-1,1));
    sol = max({sol, solve(0,n-1,0), solve(0,n-1,1)});
    printf("%d", sol);
    return 0;
}