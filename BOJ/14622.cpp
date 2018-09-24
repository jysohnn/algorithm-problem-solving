#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
ll n;
bool prime[5000001] = {1,1,0};
priority_queue<ll> a, b;
set<ll> p;
ll aa = 0, bb = 0;

int main()
{
	for (int i = 2; (i*i) <= 5000001; i++)
	{
		if (!prime[i])
			for (int j = i*i; j <= 5000001; j += i) prime[j] = 1;
	}
	cin >> n;
	while (n--)
	{
		ll x;
		scanf("%lld", &x);
		if (!prime[x])
		{
			if (p.find(x) != p.end()) aa -= 1000;
			else p.insert(x), a.push(x);
		}
		else
		{
			if (b.size() < 3) bb += 1000;
			else
			{
				ll tmp1 = b.top(); b.pop();
				ll tmp2 = b.top(); b.pop();
				bb += b.top();
				b.push(tmp2); b.push(tmp1);
			}
		}
		scanf("%lld", &x);
		if (!prime[x])
		{
			if (p.find(x) != p.end()) bb -= 1000;
			else p.insert(x), b.push(x);
		}
		else
		{
			if (a.size() < 3) aa += 1000;
			else
			{
				ll tmp1 = a.top(); a.pop();
				ll tmp2 = a.top(); a.pop();
				aa += a.top();
				a.push(tmp2); a.push(tmp1);
			}
		}
	}
	if (aa > bb) printf("소수의 신 갓대웅");
	else if (aa < bb) printf("소수 마스터 갓규성");
	else printf("우열을 가릴 수 없음");
	return 0;
}