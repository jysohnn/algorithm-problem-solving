#include <iostream>

using namespace std;
using ll = long long;

ll x;

int main()
{
	cin>>x;
	for(ll y=1; 1; y++)
		if(y*y + y + 1 >= x)
		{
			cout<< y;
			return 0;
		}
}