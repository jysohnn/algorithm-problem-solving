#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[26] = { 0 };
int n, k;
bool flag = 1;

int main()
{
 scanf("%d %d",&n,&k);
 getchar();
 for (int i = 0; i < n; i++)
 {
  char x = getchar();
  a[x - 'a']++;
 }
 for (int i = 0; i < 26; i++)
  if (a[i] > k) flag = 0;
 if (flag) printf("YES");
 else printf("NO");
 return 0;
}