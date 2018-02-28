#include <cstdio>

long long sum = 0;
int n, k;

int main()
{
 scanf("%d %d",&n,&k);
 for (int i = 1; i <= n; i++)
 {
  int candy;
  scanf("%d",&candy);
  sum += candy;
  if (sum >= 8) k -= 8, sum -= 8;
  else k -= sum, sum = 0;
  if (k <= 0)
  {
   printf("%d", i);
   return 0;
  }
 }
 printf("-1");
 return 0;
}