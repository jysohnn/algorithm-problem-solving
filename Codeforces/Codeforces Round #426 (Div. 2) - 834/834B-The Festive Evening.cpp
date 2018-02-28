#include <cstdio>
#include <cstring>

int o[26], c[26];
char s[1000001];
int open[1000001] = { 0 };
int n, k, m = 0;

int main()
{
 memset(o, -1, sizeof(o));
 memset(c, -1, sizeof(c));
 scanf("%d %d",&n,&k);
 scanf("%s",s);
 for (int i = 0; i < n; i++)
  if (o[s[i] - 'A'] == -1) o[s[i] - 'A'] = i;
 for (int i = n-1; i >= 0; i--)
  if (c[s[i] - 'A'] == -1) c[s[i] - 'A'] = i+1;
 for (int i = 0; i < 26; i++)
  for (int j = o[i]; j < c[i]; j++) open[j]++;
 for (int i = 0; i < n; i++)
  if (m < open[i]) m = open[i];
 if (m > k) printf("YES");
 else printf("NO");
 return 0;
}