#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool a[5][5] = {0};
int n;

int main()
{
	int check = 0;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin>>x>>y;
		a[x-1][y-1] = 1;
		a[y-1][x-1] = 1;
	}
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(a[i][j]) check++;
	if(a[0][2] && a[0][3] && a[2][3] && check == 6) cout<<"Wa-pa-pa-pa-pa-pa-pow!";
	else cout<<"Woof-meow-tweet-squeek";
	return 0;
}