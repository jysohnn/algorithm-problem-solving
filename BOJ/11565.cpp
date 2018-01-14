#include <iostream>
#include <string>

using namespace std;

string a,b;

int main()
{
	int x = 0,y = 0;
	cin>>a>>b;
	for(int i=0;i<a.size();i++) if(a[i] == '1') x++;
	for(int i=0;i<b.size();i++) if(b[i] == '1') y++;

	bool check = 0;

	if(x % 2 == 0 && y <= x) check = 1;
	else if(x % 2 == 1 && y <= x+1) check = 1;

	if(check) cout<<"VICTORY";
	else cout<<"DEFEAT";

	return 0;
}