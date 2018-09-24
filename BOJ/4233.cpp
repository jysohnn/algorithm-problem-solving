#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll p, a;
bool isprime[1000000]; // prime 배열, memset(isprime, 1, sizeof(isprime));
vector<long long> prime; // prime 벡터

bool is_prime(ll n)
{
    bool ret = 1;
    ll x = n;
    for(ll i=0; i<prime.size(); i++)
    {
        if(x == prime[i]) return 1;
        while(n % prime[i] == 0)
        {
            n /= prime[i];
            ret = 0;
        }
        if(n == 1) break;
    }
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

ll ppower(ll n, ll x)
{
    if(x == 1) return n;
    if(x == 0) return 1;

    ll tmp = ppower(n, x/2);
    if(x % 2 == 0) return (tmp * tmp) % p;
    else return (((tmp * tmp) % p) * n) % p;
}

int main()
{
    for(ll i=0; i<1000000; i++) isprime[i] = 1;
    make_prime(1000000001);
    while(1)
    {
        scanf("%lld %lld", &p, &a);
        if(p == 0 && a == 0) break;
        if(ppower(a, p) == a && !is_prime(p)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}