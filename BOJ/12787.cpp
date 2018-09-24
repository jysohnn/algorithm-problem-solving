#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;
int t;

ll pow(int x)
{
	ll ret = 1;
	for (int i = 0; i < x; i++) ret *= 2;
	return ret;
}

ll solve1(string& s)
{
	ll ret = 0;
	ll tmp = 0;
	int count = 56;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			ret += tmp * pow(count);
			tmp = 0;
			count -= 8;
		}
		else
		{
			tmp *= 10;
			tmp += (s[i] - '0');
		}
	}
	ret += tmp * pow(count);
	return ret;
}
void solve2(ll n)
{
	string ret;
	string ret2;
	int idx = 0;
	while (n)
	{
		ret.push_back(n % 2 + '0');
		n /= 2;
	}
	while (ret.size() != 64) ret.push_back('0');
	reverse(ret.begin(), ret.end());
	for (int i = 0; i < 8; i++)
	{
		ll tmp = 0;
		for (int j = idx; j < idx + 8; j++)
		{
			tmp *= 2;
			tmp += (ret[j] - '0');
		}
		printf("%lld", tmp);
		if (i != 7) putchar('.');
		idx += 8;
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		int x; ll n; string s;
		scanf("%d ", &x);
		if (x == 1)
		{
			cin >> s;
			printf("%llu\n", solve1(s));
		}
		else
		{
			cin >> n;
			solve2(n);
			putchar('\n');
		}
	}
	return 0;
}