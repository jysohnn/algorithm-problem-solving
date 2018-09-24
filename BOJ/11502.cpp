#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cstring>
#include <tuple>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll N = 1001;
bool isprime[N]; // fill(isprime, isprime+N, 1);
vector<ll> prime;
vector<tuple<ll, ll, ll> > v[N];

void make_prime(ll n)
{
	isprime[0] = isprime[1] = 0;
	for(ll i = 2; i <= n; i++)
	{
		if(isprime[i])
		{
			for(ll j = i*i; j < n; j += i) isprime[j] = 0;
			prime.push_back(i);
		}
	}
}

int main()
{
    fill(isprime, isprime+N, 1);
    make_prime(N);
    for(int i=0; i<prime.size(); i++)
        for(int j=i; j<prime.size(); j++)
            for(int k=j; k<prime.size(); k++)
            {
                ll x = prime[i] + prime[j] + prime[k];
                if(x < N) v[x].push_back({prime[i], prime[j], prime[k]});
            }
    
    ll t, n;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(v[n].size() == 0) printf("0\n");
        else printf("%lld %lld %lld\n", get<0>(v[n][0]), get<1>(v[n][0]), get<2>(v[n][0]));
    }
    return 0;
}