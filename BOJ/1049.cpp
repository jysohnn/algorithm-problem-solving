#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int ms = 99999999,mo = 99999999;

int main()
{
	int p = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int s,o;
		scanf("%d %d",&s,&o);
		ms = min(ms,s);
		mo = min(mo,o);
	}
	if(ms > mo * 6) ms = mo * 6;
	if(ms < mo * 6) while(n >= 6) n -= 6, p += ms;
	if(ms < mo * (n%6)) p += ms + mo * (n/6);
	else p += mo * n;
	
	printf("%d",p);
}