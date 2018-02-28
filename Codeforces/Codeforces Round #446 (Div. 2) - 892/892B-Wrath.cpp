#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
ll a[1000001];
ll n, kill = 0, sol = 0;

int main()
{
 cin>>n;
 for(int i=0;i<n;i++) scanf("%lld",a+i);
 for(int i=n-1;i>=0;i--)
 {
  if(kill) sol++, kill--;
  if(a[i] > kill) kill = a[i];
 }
 cout<<n-sol;
 return 0;
}