#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
ll n;
ll sol = 0;

ll solve(ll x)
{
    if(x==0) return 1;
    if(x%2==1) return (2*(solve(x/2)%MOD)*(solve(x/2)%MOD)) % MOD;
    else return ((solve(x/2)%MOD)*(solve(x/2)%MOD)) % MOD;
}

int main()
{
    scanf("%lld", &n);
    for(int i=0;i<n;i++)
    {
        ll x, y;
        scanf("%lld %lld",&x,&y);
        sol += (solve(y-1) * ((x * y) % MOD)) % MOD;
        sol %= MOD;
    }
    printf("%lld", sol);
    return 0;
}