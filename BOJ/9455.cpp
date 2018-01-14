#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
ll t;
ll n, m;
int a[101][101];

int main()
{
	cin>>t;
	while(t--)
	{
		ll sol = 0;
		memset(a, 0, sizeof(a));
		scanf("%lld %lld",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) scanf("%d", &a[i][j]);
		for(int j=0;j<m;j++)
		{
			ll sum = 0;
			for(int i=n-1;i>=0;i--)
			{
				if(a[i][j] == 0) sum++;
				else sol += sum;
			}
		}
		printf("%lld\n",sol);
	}
	return 0;
}