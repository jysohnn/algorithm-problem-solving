#include <cstdio>
int map[301][301]={0};
bool adj[301][301];
int n,m;
int year=0;

void melt()
{
	int check[301][301]={0};
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!=0)
			{
				if(i!=0 && map[i-1][j]==0) check[i][j]++;
				if(j!=0 && map[i][j-1]==0) check[i][j]++; 
				if(i!=n-1 && map[i+1][j]==0) check[i][j]++;
				if(j!=m-1 && map[i][j+1]==0) check[i][j]++;
			}
			else check[i][j]=0;
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			map[i][j]-=check[i][j];
			if(map[i][j]<0) map[i][j]=0;
		}
};

void dfscheck(int x,int y)
{
	adj[x][y]=true;
	if(x-1>0 && map[x-1][y]!=0 && adj[x-1][y]==false)
	{
		dfscheck(x-1,y);
	}
	if(y-1>0 && map[x][y-1]!=0 && adj[x][y-1]==false)
	{
		dfscheck(x,y-1);
	}
	if(x+1<n && map[x+1][y]!=0 && adj[x+1][y]==false)
	{
		dfscheck(x+1,y);
	}
	if(y+1<m && map[x][y+1]!=0 && adj[x][y+1]==false)
	{
		dfscheck(x,y+1);
	}
	return;
};

bool dividecheck()
{
	int check=0,zerocheck=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) adj[i][j]=false;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!=0 && adj[i][j]==false)
			{
				if(check>=1) return true;
				else check++;

				dfscheck(i,j);
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			zerocheck+=map[i][j];
		}
	if(zerocheck==0)
	{
		year=0;
		return true;
	}
	return false;
};

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) scanf("%d",*(map+i)+j);
	
	while(1)
	{
		if(dividecheck())
		{
			printf("%d\n",year);
			return 0;
		}
		melt();
		year++;
	};
	return 0;
}