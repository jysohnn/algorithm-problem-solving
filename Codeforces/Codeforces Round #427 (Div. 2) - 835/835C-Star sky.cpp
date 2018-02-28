#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, q, c;
vector<int> l[101][101];
int d[11][101][101] = { 0 };

int main()
{
 scanf("%d %d %d",&n,&q,&c);
 for (int i = 0; i < n; i++)
 {
  int x, y, r;
  scanf("%d %d %d",&x,&y,&r);
  l[x][y].push_back(r);
 }
 for (int i = 0; i < 101; i++)
  for (int j = 0; j < 101; j++)
  {
   d[0][i][j] = d[0][i - 1][j] + d[0][i][j - 1] - d[0][i - 1][j - 1];
   for(int r = 0;r<l[i][j].size();r++) d[0][i][j] += l[i][j][r];
  }
 for (int k = 1; k < 11; k++)
  for (int i = 0; i < 101; i++)
   for (int j = 0; j < 101; j++)
   {
    d[k][i][j] = d[k][i - 1][j] + d[k][i][j - 1] - d[k][i - 1][j - 1];
    if (l[i][j].size())
     for(int r = 0; r<l[i][j].size();r++)
     {
      l[i][j][r] = (l[i][j][r] + 1) % (c+1);
      d[k][i][j] += l[i][j][r];
     }
   }
 for (int i = 0; i < q; i++)
 {
  int t, x1, y1, x2, y2;
  int sol;
  scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
  t %= (c+1);
  sol = d[t][x2][y2] - d[t][x1-1][y2] - d[t][x2][y1-1] + d[t][x1-1][y1-1];
  printf("%d\n",sol);
 }
 return 0;
}