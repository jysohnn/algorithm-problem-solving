#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
multiset<ll> s;
int t, n;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		scanf("%d",&n);
		while(n--)
		{
			getchar();
			char x; ll y;
			scanf("%c %lld", &x, &y);
			if(x == 'I') s.insert(y);
			else if(x == 'D')
			{
				if(y == -1 && !s.empty()) s.erase(s.begin());
				else if(y == 1 && !s.empty()) s.erase(--s.end());
			}
		}
		if(s.empty()) printf("EMPTY\n");
		else printf("%lld %lld\n",*s.rbegin(), *s.begin());
	}
	return 0;
}