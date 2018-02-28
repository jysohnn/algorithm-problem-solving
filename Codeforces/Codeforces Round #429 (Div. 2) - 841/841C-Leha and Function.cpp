#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[200001];
int sol[200001];
pair<int,int> b[200001];

int main()
{
 scanf("%d",&n);
 for (int i = 0; i < n; i++) scanf("%d", a + i);
 for (int i = 0; i < n; i++)
 {
  int x;
  scanf("%d", &x);
  b[i].first = x;
  b[i].second = i;
 }
 sort(a, a + n);
 sort(b, b + n);
 for (int i = 0; i < n; i++) sol[b[i].second] = a[n-i-1];
 for (int i = 0; i < n; i++) printf("%d ", sol[i]);
}