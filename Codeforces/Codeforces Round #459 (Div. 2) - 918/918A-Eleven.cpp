#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

bool c[1001] = { 0 };

int main()
{
 int x = 1, y = 1;
 while (x < 1010)
 {
  c[x] = 1;
  int tmp = y;
  y = x + y;
  x = tmp;
 }
 int k;
 cin >> k;
 for (int i = 1; i <= k; i++)
 {
  if (c[i]) printf("O");
  else printf("o");
 }
  
 return 0;
}