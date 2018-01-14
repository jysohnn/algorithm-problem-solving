#include <iostream>
using namespace std;
int n,a[501][501];
int main()
{
	ios::sync_with_stdio(0);
	int i,j,m=0;
	a[0][2] = 0;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			cin>>a[i][j];
			if(j == 1) a[i][j] += a[i-1][j];
			else if(j == i) a[i][j] += a[i-1][j-1];
			else a[i][j] += a[i-1][j] > a[i-1][j-1] ? a[i-1][j] : a[i-1][j-1];
			if(i == n && m < a[i][j]) m = a[i][j];
		}
	cout<<m;
	return 0;
}