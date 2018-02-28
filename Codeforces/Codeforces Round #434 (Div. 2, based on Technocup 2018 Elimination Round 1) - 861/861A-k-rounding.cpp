#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

int main() {
 double n, k, i=1;
 long long ans;
 scanf("%lf%lf", &n, &k);
 k = pow(10.0, k);
 while(1) {
  ans = n*i;
  if(ans %(int)k== 0)break;
  i++;
 }
 printf("%lld", ans);
}