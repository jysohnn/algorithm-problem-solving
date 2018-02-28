#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s;
int sol = 0;

int main()
{
 cin >> s;
 for(int i=0;i<s.size();i++)
  if ('0' <= s[i] && s[i] <= '9')
  {
   if ((s[i] - '0') % 2 == 1) sol++;
  }
  else
  {
   if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
    || s[i] == 'o' || s[i] == 'u') sol++;
  }
 cout << sol;
 return 0;
}