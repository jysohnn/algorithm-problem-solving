#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, idx = 0;
stack<int> s;
queue<int> q;

int main()
{
	bool sol = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	for (int i = 1; i <= n; i++)
	{
		bool check = 0;
		if (!s.empty() && s.top() == i) s.pop(), check = 1;
		else
		{
			while(!q.empty())
			{
				if (q.front() == i) { q.pop(); check = 1; break; }
				else s.push(q.front()), q.pop();
			}
		}
		if (!check)
		{
			printf("Sad"); return 0;
		}
	}
	printf("Nice");
	return 0;
}