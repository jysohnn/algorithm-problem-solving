#include <cstdio>

long long n, k;

int main()
{
 scanf("%I64d %I64d",&n,&k);
 if((n/k) % 2 == 1) printf("YES");
 else printf("NO");
 return 0;
}