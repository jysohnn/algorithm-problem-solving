#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int dp[1001] = { 0,1,3 };

int main()
{
	cin >> n;
	for (int i = 3; i <= n; i++) dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
	cout << dp[n];
	return 0;
}