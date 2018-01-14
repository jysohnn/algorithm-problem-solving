#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll t,n,k;

int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		vector<ll> v[4];
		vector<ll> sum[2];

		scanf("%lld %lld",&k,&n);
		for(int i=0;i<4;i++)
			for(int j=0; j<n; j++)
			{
				ll x; scanf("%lld",&x);
				v[i].push_back(x);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) sum[0].push_back(v[0][i] + v[1][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) sum[1].push_back(v[2][i] + v[3][j]);
		sort(sum[1].begin(),sum[1].end());

		ll sol = sum[0][0] + sum[1][0];
		
		for(int i=0; i<sum[0].size(); i++)
		{
			ll x = sum[0][i];
			if(x > k)
			{
				ll tmp = x+sum[1][0];
				if(abs(tmp-k) < abs(sol-k)) sol = tmp;
				else if(abs(tmp-k) == abs(sol-k) && tmp < sol) sol = tmp;
			}
			else
			{
				auto it = lower_bound(sum[1].begin(), sum[1].end(), k-x);
				if(it != sum[1].end())
				{
					ll tmp = x + *it;
					if(abs(tmp-k) < abs(sol-k)) sol = tmp;
					else if(abs(tmp-k) == abs(sol-k) && tmp < sol) sol = tmp;
				}
				if(it != sum[1].begin())
				{
					it--;
					ll tmp = x + *it;
					if(abs(tmp-k) < abs(sol-k)) sol = tmp;
					else if(abs(tmp-k) == abs(sol-k) && tmp < sol) sol = tmp;
				}
			}
		}
		printf("%lld\n",sol);
	}
	return 0;
}