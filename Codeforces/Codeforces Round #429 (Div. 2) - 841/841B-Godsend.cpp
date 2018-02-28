#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, sol = 0;

int main()
{
 scanf("%d",&n);
 for (int i = 0; i < n; i++)
 {
  long long x;
  scanf("%I64d",&x);
  if (x % 2 == 1) sol++;
 }
 if (sol == 0) printf("Second");
 else if (sol % 2 == 1) printf("First");
 else printf("First");
}