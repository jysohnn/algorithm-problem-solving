#include <iostream>
#include <string>

using namespace std;

string x;

int main()
{
	cin>>x;
	if(x.size() > 1 && x[0] == '0')
	{
		int sol = 0;
		if(x[1] == 'x')
		{
			for(int i=2;i<x.size();i++)
			{
				sol *= 16;
				if('0' <= x[i] && x[i] <= '9') sol += (x[i] - '0');
				else sol += (x[i] - 'a' + 10);	
			}
			cout<<sol;
		}
		else
		{
			for(int i=1;i<x.size();i++)
			{
				sol *= 8;
				sol += (x[i] - '0');
			}
			cout<<sol;
		}
	}
	else cout<<x;
	return 0;
}