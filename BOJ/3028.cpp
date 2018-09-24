#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

bool sol[3] = { 1,0,0 };
string q;

int main()
{
	cin >> q;
	for (int i = 0; i < q.size(); i++)
	{
		if (q[i] == 'A') swap(sol[0], sol[1]);
		else if (q[i] == 'B') swap(sol[1], sol[2]);
		else swap(sol[0], sol[2]);
	}
	for (int i = 0; i < 3; i++)
		if (sol[i]) printf("%d", i + 1);
	return 0;
}