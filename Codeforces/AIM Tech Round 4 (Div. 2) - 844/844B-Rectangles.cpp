#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int a[51][51];
long long d[51];
int main()
{
 int n, m;
 long long sum = 0;
 scanf("%d %d", &n, &m);
 for (int i = 0; i < n; i++)
 {
  for (int j = 0; j < m; j++)
  {
   scanf("%d", &a[i][j]);
  }
 }
 d[0] = 1;
 d[1] = 2;
 for (int i = 2; i < 51; i++)
  d[i] = d[i - 1] * 2;
 for (int i = 0; i < n; i++)
 {
  int w = 0, b = 0;
  for (int j = 0; j < m; j++)
  {
   if (a[i][j] == 0) w++;
   else b++;
  }
  if( w != 0)
   sum += d[w] - 1;
  if( b != 0)
   sum += d[b] - 1;
 }
 for (int i = 0; i < m; i++)
 {
  int w = 0, b = 0;
  for (int j = 0; j < n; j++)
  {
   if (a[j][i] == 0) w++;
   else b++;
  }
  if( w != 0)
   sum += (d[w] - 1 - w);
  if( b != 0)
   sum += (d[b] - 1 - b);
 }
 printf("%I64d\n", sum);
 return 0;
}