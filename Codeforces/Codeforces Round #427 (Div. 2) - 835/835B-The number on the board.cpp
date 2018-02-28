#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int k, sol = 0;
long long sum = 0;
vector<int> num;

int main()
{
 scanf("%d",&k);
 getchar();
 while (1)
 {
  char c = getchar();
  if (c == '\n' || c == EOF) break;
  num.push_back(c - '0');
  sum += (c - '0');
 }
 sort(num.begin(), num.end());
 if (sum >= k) printf("0");
 else
 {
  for (int i = 0; i < num.size(); i++)
  {
   if (num[i] != 9)
   {
    sum += (9 - num[i]);
    sol++;
    if (sum >= k) break;
   }
  }
  printf("%d",sol);
 }
 return 0;
}