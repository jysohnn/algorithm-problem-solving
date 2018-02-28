#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
ll b[100001];
ll n, sum = 0;

int main()
{
 cin>>n;
 for(int i=0;i<n;i++)
 {
  ll x;
  scanf("%lld", &x);
  sum += x;
 }
 for(int i=0;i<n;i++) scanf("%lld", b+i);
 sort(b,b+n);
 if(b[n-1] + b[n-2] >= sum) printf("YES");
 else printf("NO");
 return 0;
}