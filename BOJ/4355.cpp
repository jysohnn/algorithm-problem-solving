#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll x;
bool isprime[1000000]; // prime 배열, memset(isprime, 1, sizeof(isprime));
vector<long long> prime; // prime 벡터

ll solve(ll n)
{
    ll ret = 1;
    for(ll i=0; i<prime.size(); i++)
    {
        ll p = 0;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            p++;
        }
        if(p) ret *= (pow(prime[i], p) - pow(prime[i], p-1));
        if(n == 1) break;
    }
    if(n != 1) ret *= (n - 1);
    return ret;
}

void make_prime(long long n)
{
	isprime[0] = isprime[1] = 0;
	long long sq = (long long)sqrt(n);
	for(long long i = 2; i <= sq; i++)
	{
		if(isprime[i])
		{
			for(long long j = i*i; j < 1000000; j += i) isprime[j] = 0;
			prime.push_back(i);
		}
	}
}

int main()
{
    for(ll i=0; i<1000000; i++) isprime[i] = 1;
    make_prime(1000000001);
    while(1)
    {
        scanf("%lld", &x);
        if(x == 0) break;
        printf("%lld\n", solve(x));
    }
    return 0;
}