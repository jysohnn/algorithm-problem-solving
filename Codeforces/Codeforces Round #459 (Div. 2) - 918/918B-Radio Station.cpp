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

map<string, string> s;
ll n, m;

int main()
{
 cin >> n >> m;
 for (int i = 0; i < n; i++)
 {
  char name[50], ip[50];
  scanf("%s %s", name, ip);
  s[string(ip)] = string(name);
 }
 for (int i = 0; i < m; i++)
 {
  char name[50], ip[50];
  scanf("%s %s", name, ip);
  string ipp = string(ip);
  ipp.pop_back();
  printf("%s %s #%s\n", name, ip, s[ipp].c_str());
 }
 return 0;
}