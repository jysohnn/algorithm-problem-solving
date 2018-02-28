#include <cstdio>

int n, k;
int a[101];

int main()
{
 int f, t, o = 0;
 scanf("%d %d",&n,&k);
 f = n, t = 2 * n;
 for (int i = 0; i < k; i++) scanf("%d", a + i);
 for (int i = 0; i < k; i++)
 {
  if (f >= a[i] / 4) f -= a[i] / 4, a[i] %= 4;
  else a[i] -= 4 * f, f = 0;
 }
 for (int i = 0; i < k; i++)
 {
  if (f >= a[i] / 3) f -= a[i] / 3, a[i] %= 3;
  else a[i] -= 3 * f, f = 0;
 }
 for (int i = 0; i < k; i++)
 {
  if (t >= a[i] / 2) t -= a[i] / 2, a[i] %= 2;
  else a[i] -= 2 * t, t = 0;
 }
 for (int i = 0; i < k; i++)
 {
  if (f >= a[i] / 2) f -= a[i] / 2, o += a[i] / 2, a[i] %= 2;
  else a[i] -= 2 * f, o += f ,f = 0;
 }
 o += f * 2;
 o += t;
 for (int i = 0; i < k; i++)
 {
  if (o >= a[i]) o -= a[i], a[i] = 0;
  else a[i] -= o, o = 0;
 }
 for (int i = 0; i < k; i++)
  if (a[i] != 0)
  {
   printf("NO");
   return 0;
  }
 printf("YES");
 return 0;
}