#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

string dir;
ll n, m, sx, sy, ex, ey, sol = 0;
const int dx[4] = { 1,-1,0,0 };
const int dy[4] = { 0,0,1,-1 };
int mm[4];
char map[51][51];

ll solve(ll x, ll y)
{
 for (int i = 0; i < dir.size(); i++)
 {
  int d = dir[i] - '0';
  x += dx[mm[d]];
  y += dy[mm[d]];
  if (x < 0 || x >= n || y < 0 || y >= m) return 0;
  if (map[x][y] == '#') return 0;
  if (map[x][y] == 'E') return 1;
 }
 if (map[x][y] == 'E') return 1;
 else return 0;
}

int main()
{
 cin >> n >> m;
 for (int i = 0; i < n; i++)
 {
  getchar();
  for (int j = 0; j < m; j++)
  {
   scanf("%1c", &map[i][j]);
   if (map[i][j] == 'S') sx = i, sy = j;
  }
 }
 cin >> dir;
 for(int i=0;i<4;i++)
  for (int j = 0; j < 4; j++)
  {
   if (i == j) continue;
   for (int k = 0; k < 4; k++)
   {
    if (k == i || k == j) continue;
    for (int l = 0; l < 4; l++)
    {
     if (l == i || l == j || l == k) continue;
     mm[0] = i, mm[1] = j, mm[2] = k, mm[3] = l;
     sol += solve(sx, sy);
    }
   }
    
  }
   
 cout << sol;
 return 0;
}