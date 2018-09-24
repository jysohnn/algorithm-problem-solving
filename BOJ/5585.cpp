#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n, sol = 0;
ll list[6] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	cin >> n; n = 1000 - n;
	for(int i=0;i<6;i++)
		if (n >= list[i]) sol += n / list[i], n %= list[i];
	cout << sol;
	return 0;
}