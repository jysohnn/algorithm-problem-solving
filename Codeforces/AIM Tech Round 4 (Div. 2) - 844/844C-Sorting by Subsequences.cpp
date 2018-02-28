#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ss {
 int v, i;
};
ss aa[100001];
ss bb[100001];
int visit[100001];
vector<int> v[100001];
bool mysort(ss a, ss b) {
 if (a.v < b.v) return true;
 return false;
}
int main()
{
 int n;
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  int tmp;
  scanf("%d", &tmp);
  aa[i].v = tmp;
  bb[i].v = tmp;
  bb[i].i = i;
 }
 sort(bb, bb + n, mysort);
 for (int i = 0; i < n; i++)
  aa[bb[i].i].i = i;

 for (int i = 0; i < n; i++)
 {
  if (!visit[i])
  {
   int mother = i;
   v[mother].push_back(i);
   visit[i] = 1;
   int cur = i;
   while (1)
   {
    int index = aa[cur].i;
    if (visit[index]) break;
    v[mother].push_back(index);
    visit[index] = 1;
    cur = index;
   }
  }
 }
 int maxx = 0;
 for (int i = 0; i < n; i++)
  if (v[i].size() != 0) maxx++;
 printf("%d\n", maxx);
 for (int i = 0; i < n; i++)
 {
  if (v[i].size() != 0)
  {
   printf("%d ", v[i].size());
   for (int j = 0; j < v[i].size(); j++)
    printf("%d ", v[i][j] + 1);
   puts("");
  }
 }
 return 0;
}