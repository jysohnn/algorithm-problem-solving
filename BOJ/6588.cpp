#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 1000001;
bool isprime[N];

void make_prime(long long n)
{
	isprime[0] = isprime[1] = 0;
	long long sq = (long long)sqrt(n);
	for(long long i = 2; i <= sq; i++)
		if(isprime[i])
			for(long long j = i*i; j <= n; j += i) isprime[j] = 0;
}

int t;
int main()
{
	fill(isprime, isprime + N, 1);
	make_prime(N-1);
	while(1)
	{
		ll a, b;
		ll x; scanf("%lld", &x);
		if(!x) break;
		for(int i=2;i*2<=x;i++)
			if(isprime[i] && isprime[x-i])
			{
				a = i; b = x-i; break;
			}
		printf("%lld = %lld + %lld\n", x, a, b);
	}
	return 0;
}