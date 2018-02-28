#include <iostream>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;
int n, k;
pii sol[300001];
pii a[300001];
set<int> s;
long long sum = 0;

int main()
{
 cin >> n >> k;
 for (int i = 0; i < n; i++)
 {
  int x; scanf("%d",&x);
  a[i].first = x; a[i].second = i + 1;
 }
 for (int i = 1; i <= n; i++) s.insert(k + i);
 sort(a, a + n, greater<pii>());
 for (int i = 0; i < n; i++)
 {
  auto it = s.find(a[i].second);
  if (it != s.end())
  {
   sol[a[i].second - 1].first = a[i].first;
   sol[a[i].second - 1].second = a[i].second;
   s.erase(it);
  }
  else
  {
   auto itt = s.upper_bound(a[i].second);
   sol[a[i].second - 1].first = a[i].first;
   sol[a[i].second - 1].second = *itt;
   s.erase(itt);
  }
 }
 for (int i = 0; i < n; i++) sum += (long long)sol[i].first * (long long)(sol[i].second - i - 1);
 cout << sum << '\n';
 for (int i = 0; i < n; i++) printf("%d ",sol[i].second);
 return 0;
}