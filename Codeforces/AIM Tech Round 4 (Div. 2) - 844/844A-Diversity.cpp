#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string a;
bool v[26] = { 0 };
int n;

int main()
{
 cin >> a >> n;
 if (a.size() < n) printf("impossible");
 else
 {
  int check = 0;
  for (int i = 0; i < a.size(); i++) v[a[i] - 'a'] = 1; 
  for (int i = 0; i < 26; i++) if (v[i]) check++;
  if (n <= check) printf("0");
  else printf("%d",n-check);
 }
 return 0;
}