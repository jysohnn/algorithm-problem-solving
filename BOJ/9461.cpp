#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll a[101] = {0,1,1,1,2,2,3,4};
ll n;

int main()
{
	cin>>n;
	for(int i=4;i<101;i++) a[i] = a[i-2]+a[i-3];
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",a[x]);
	}
	return 0;
}