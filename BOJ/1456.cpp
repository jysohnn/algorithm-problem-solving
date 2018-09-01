#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll p, a;
bool isprime[10000001]; // prime 배열, memset(isprime, 1, sizeof(isprime));
vector<ll> prime; // prime 벡터
vector<ll> sol;

void make_prime(ll n)
{
	isprime[0] = isprime[1] = 0;
	ll sq = (ll)sqrt(n);
	for(ll i = 2; i <= sq; i++)
	{
		if(isprime[i])
		{
			for(ll j = i*i; j < 10000001; j += i) isprime[j] = 0;
			prime.push_back(i);
		}
	}
}

int main()
{
    for(ll i=0; i<10000001; i++) isprime[i] = 1;
    make_prime((ll)100000000000001);
    for(ll i=0; i<prime.size(); i++)
    {
        ll x = prime[i];
        while(1)
        {
            if((double)x > (double)100000000000000 / double(prime[i])) break;
            sol.push_back(x * prime[i]);
            x *= prime[i];
        }
    }
    ll a, b, ssol = 0;
    cin>>a>>b;
    for(ll i=0; i<sol.size(); i++)
        if(a <= sol[i] && sol[i] <= b) ssol++;
    cout<<ssol;
    return 0;
}