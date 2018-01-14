#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	priority_queue<int> h;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x == 0)
		{
			if(h.size() == 0) printf("0\n");
			else {printf("%d\n",h.top()); h.pop();}
		}
		else h.push(x);
	}
	return 0;
}