#include <cstdio>
#include <queue>

using namespace std;

struct trp
{
	int f;
	int s;
	int level;
	trp(int a, int b,int c):f(a),s(b),level(c){}
};

queue<trp> q;
bool a[100][100] = {0};
bool v[100][100] = {0};
int n,m;
int imove[4] = {0,0,1,-1};
int jmove[4] = {1,-1,0,0};

bool bCheck(int x,int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;	
}

int bfs()
{
	q.push(trp(0,0,1));
	v[0][0] = true;
	while(!q.empty())
	{
		trp c = q.front();
		q.pop();
		if(c.f == n-1 && c.s == m-1) return c.level;
		for(int i=0;i<4;i++)
			if(bCheck(c.f + imove[i], c.s + jmove[i]) && a[c.f + imove[i]][c.s + jmove[i]] && !v[c.f + imove[i]][c.s + jmove[i]]) 
			{
				v[c.f + imove[i]][c.s + jmove[i]] = true;
				q.push(trp(c.f + imove[i], c.s + jmove[i], c.level+1));
			}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		char tmp[101];
		scanf("%s",tmp);
		for(int j=0;j<m;j++)
		{
			if(tmp[j] == '0') a[i][j] = false;
			else a[i][j] = true;
		}
	}
	
	printf("%d",bfs());
	return 0;
}