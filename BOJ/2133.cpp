#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[31] = {1,0,3};

int main()
{
	for(int i=4; i<31; i++)
		if(i % 2 == 0)
		{
			a[i] = 3*a[i-2];
			for(int j = 4; i-j >= 0; j += 2) a[i] += 2*a[i-j];
		}
	cin>>n;
	cout<<a[n];
	return 0;
}