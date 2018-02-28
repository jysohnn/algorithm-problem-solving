#include <cstdio>
#include <cstring>

bool good[26] = { 0 };
char pat[100002], str[100002];
int d[100002];
int q, ps, ss;

bool match(int p, int s)
{
 if (pat[p] == 0 && str[s] == 0) return true;
 if (pat[p] == 0 && str[s] != 0) return false;
 if (pat[p] != '*' && pat[p] != 0 && str[s] == 0) return false;
 if (pat[p] == '*')
 {
  if (d[s] != -1) return d[s];
  bool ret;
  if(ret = match(p + 1, s)) return d[s] = ret;
  if (str[s] != 0 && !good[str[s] - 'a'])
  {
   if(ret = match(p, s + 1)) return d[s] = ret;
   if(ret = match(p + 1, s + 1)) return d[s] = ret;
  }
  return d[s] = ret;
 }
 else if (pat[p] == '?')
 {
  if (!good[str[s]-'a']) return false;
  else return match(p + 1, s + 1);
 }
 else
 {
  if (pat[p] == str[s]) return match(p + 1, s + 1);
  else return false;
 }
}

int main()
{
 while (1)
 {
  char c = getchar();
  if (c == '\n') break;
  good[c - 'a'] = 1;
 }
 scanf("%s", pat);
 scanf("%d", &q);
 while (q--)
 {
  memset(d, -1, sizeof(d));
  memset(str, 0, sizeof(str));
  scanf("%s", str);
  if (match(0, 0)) printf("YES\n");
  else printf("NO\n");
 }
 return 0;
}