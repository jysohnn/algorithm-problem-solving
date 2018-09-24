#include <iostream>

using namespace std;

int n;
int a[101],b[101];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>b[i];
	a[0] = b[0], cout<<a[0]<<' ';
	for(int i=1;i<n;i++) 
	{
		a[i] = b[i] * (i+1);
		for(int j=0;j<i;j++) a[i] -= a[j];
		cout<<a[i]<<' ';
	}
	return 0;
}