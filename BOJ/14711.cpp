#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int n; string str;
int sol[1000][1000] = {0};
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

bool bc(int x, int y)
{
	if(x >= 0 && x < n && y >= 0 && y < n) return 1;
	else return 0;
}

int main()
{
	scanf("%d",&n);
	cin>>str;
	for(int i=0;i<n;i++)
		if(str[i] == '#') sol[0][i] = 1;

	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(sol[i][j])
			{
				int c = 1;
				for(int k=1; k<4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(bc(nx, ny) && sol[nx][ny]) c++;
				}
				if(c % 2 == 0) sol[i+1][j] = 1;
				else sol[i+1][j] = 0;
			}
			else
			{
				int c = 0;
				for(int k=1; k<4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(bc(nx, ny) && sol[nx][ny]) c++;
				}
				if(c % 2 == 0) sol[i+1][j] = 0;
				else sol[i+1][j] = 1;
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(sol[i][j] == 0) printf(".");
			else printf("#");
		}
		putchar('\n');
	}
	return 0;
}