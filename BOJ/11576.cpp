#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll a, b, n, v = 0;
vector<int> sol;

int main()
{
	cin>>a>>b>>n;
	for(int i=0; i<n; i++)
	{
		ll x; scanf("%lld",&x);
		v *= a; v += x;
	}
	while(v) sol.push_back(v%b), v /= b;
	for(auto it = sol.rbegin(); it != sol.rend(); it++) printf("%d ", *it);
	return 0;
}