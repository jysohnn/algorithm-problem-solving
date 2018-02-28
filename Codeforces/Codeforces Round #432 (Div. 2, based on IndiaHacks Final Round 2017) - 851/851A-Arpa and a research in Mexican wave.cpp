#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
int n, k, t;

int main()
{
 scanf("%d %d %d",&n, &k, &t);
 if (t - k < 0)
 {
  if (t > n) t = n;
  printf("%d", t);
 }
 else
 {
  if (t - k >= n) printf("0");
  else if(t > n) printf("%d",n-t+k);
  else printf("%d", k);
 }
 return 0;
}