#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

struct point
{
 int x[5];
};
int n;
vector<point> v;
vector<int> sol;

point vecXY(point x, point y)
{
 point ret;
 for (int i = 0; i < 5; i++) ret.x[i] = y.x[i] - x.x[i];
 return ret;
}
bool isgood(point x, point y)
{
 long long sum = 0;
 for (int i = 0; i < 5; i++) sum += x.x[i] * y.x[i];
 if (sum <= 0) return 1;
 else return 0;
}

int main()
{
 scanf("%d", &n);
 for (int i = 0; i < n; i++)
 {
  point tmp;
  for (int j = 0; j < 5; j++) scanf("%d",&(tmp.x[j]));
  v.push_back(tmp);
 }
 for (int i = 0; i < v.size(); i++)
 {
  bool flag = 0;
  for (int j = 0; j < v.size(); j++)
  {
   for (int k = j + 1; k < v.size(); k++)
    if (j != i && k != i)
    {
     point q = vecXY(v[i], v[j]);
     point w = vecXY(v[i], v[k]);
     if (!isgood(q, w)) { flag = 1; break; }
    }
   if (flag) break;
  }
  if (!flag) sol.push_back(i + 1);
 }
 printf("%d\n",sol.size());
 for (int i = 0; i < sol.size(); i++) printf("%d\n",sol[i]);
 return 0;
}