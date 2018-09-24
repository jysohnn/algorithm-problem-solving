#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, k;
vector<ll> sol;
bool nPrime[1001] = { 0 };

int main()
{
	cin >> n >> k;
	for (ll i = 2; i <= n; i++)
		if(!nPrime[i])
			for (ll j = i; j <= n; j += i)
				if (!nPrime[j]) nPrime[j] = 1, sol.push_back(j);
	cout << sol[k - 1];
	return 0;
}